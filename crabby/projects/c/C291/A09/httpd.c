/* 
 * httpd2.c
 *
 * Programmer: Charles Moye
 *
 * Basic flow: users runs program with a file containing http requests, program parses the requests and returns the response code, response headers, uri content if it exists,
 * request method, uri, and version, and the request headers. response will be stdout, info will be to stderr.
*/


/*    include    */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h>  
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "httpd.h"

/*    functions    */

char docroot[MAX_BUFFER];
char* fretrvs_replacement(const char* uri)
{
    static char buffer[MAX_BUFFER];
    char path[MAX_BUFFER];
    snprintf(path, MAX_BUFFER, "%s%s", docroot, uri);
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("path error");
        return NULL;
    }

    if (S_ISDIR(st.st_mode)) {
        DIR* dir = opendir(path);
        if (!dir) {
            perror("error opening dir");
            return NULL;
        }

        struct dirent* entry;
        static char html[MAX_BUFFER];
        snprintf(html, sizeof(html), "<HTML>\n<BODY>\n<TABLE>\n");

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            char fullpath[MAX_BUFFER];
            if (strlen(path) + 1 + strlen(entry->d_name) + 1 <= MAX_BUFFER) {
                strncat(fullpath, path, MAX_BUFFER - strlen(fullpath) - 1);
                strncat(fullpath, "/", MAX_BUFFER - strlen(fullpath) - 1);
                strncat(fullpath, entry->d_name, MAX_BUFFER - strlen(fullpath) - 1);
            } else {
                fprintf(stderr, "combined path too long, skipping: %s/%s\n", path, entry->d_name);
                continue;
            }

            if (stat(fullpath, &st) == -1) {
                perror("error retrv file stats");
                continue;
            }
            if (S_ISDIR(st.st_mode)) {
                snprintf(buffer, sizeof(buffer), "<TR><TD>%s/</TD><TD>-- bytes</TD></TR>\n", entry->d_name);
            } else {
                snprintf(buffer, sizeof(buffer), "<TR><TD>%s</TD><TD>%ld bytes</TD></TR>\n", entry->d_name, st.st_size);
            }
            strncat(html, buffer, sizeof(html) - strlen(html) - 1);
        }
        closedir(dir);
        strncat(html, "</TABLE>\n</BODY>\n</HTML>\r\n\r\n", sizeof(html) - strlen(html) - 1);
        return html;
    } else {
        FILE* file = fopen(path, "r");
        if (!file) {
            perror("error opening file");
            return NULL;
        }
        size_t read = fread(buffer, 1, sizeof(buffer) - 1, file);
        if (read == 0) {
            if (ferror(file)) {
                perror("error reading file");
            }
            fclose(file);
            return NULL;
        }
        buffer[read] = '\0';
        fclose(file);
        return buffer;
    }
}


// +---------------+
// | parse_request |
// +---------------+
// takes a file provided from stdin and expects http requests. scans first line searching for method, uri, and version, stores them and scans the rest of the lines searching for
// header:value pairs to add to the headers[][][] array. passes uri to fretrvs() and stores it in int found. checks if the code is 501, and ends after printing necessary info.
// then checks if found holds data, if so checks for get or post method and prints relevant info, if not, assume code 404 and print relevant info.

void parse_request(FILE* input, FILE* output) {
    char line[MAX_LINE_LEN];
    char method[MAX_HDR_LEN], uri[MAX_HDR_LEN], version[MAX_HDR_LEN];
    char headers[MAX_HEADERS][PAIR][MAX_HDR_LEN];
    int header_count = 0;

    if (!fgets(line, sizeof(line), input)) {
        fprintf(stderr, "Error reading request\n");
        return;
    }

    if (sscanf(line, "%s %s %s", method, uri, version) != 3) {
        fprintf(stderr, "Could not parse request line (%s)\n", line);
        return;
    }
    
    // iterate through each line checking for 2 specific values, if line has 1 specific value declare it as POST Content. store values in header, value, and strncpy to headers array
    while (fgets(line, sizeof(line), input)) {
        if (strcmp(line, "\r\n") == 0 || strcmp(line, "\n") == 0) {
            break;
        }
        char header[MAX_HDR_LEN], value[MAX_HDR_LEN];
        if (sscanf(line, "%[^:]: %[^\r\n]", header, value) == 2) {
            strncpy(headers[header_count][0], header, MAX_HDR_LEN - 1);
            strncpy(headers[header_count][1], value, MAX_HDR_LEN - 1);
            header_count++;
        // } else if (sscanf(line, "%[^\r\n]", value) == 1) {
        //     strncpy(headers[header_count][0], "POST Content: ", MAX_HDR_LEN - 1);
        //     strncpy(headers[header_count][1], value, MAX_HDR_LEN - 1);
        //     header_count++;
        }
    }
    int content_length = 0;
    for (int i = 0; i < header_count; i++) {
        if (strcasecmp(headers[i][0], "Content-Length") == 0) {
            content_length = atoi(headers[i][1]);
            break;
        }
    }
    if (content_length > 0) {
        char* body = malloc(content_length + 1);
        if (!body) {
            fprintf(stderr, "post content malloc failed\n");
            return;
        }
        size_t totalread = 0;
        while (totalread < content_length) {
            size_t n = fread(body + totalread, 1, content_length - totalread, input);
            if (n == 0) break;
            totalread += n;
        }
        body[content_length] = '\0';
        strncpy(headers[header_count][0], "POST Content: ", MAX_HDR_LEN - 1);
        strncpy(headers[header_count][1], body, MAX_HDR_LEN - 1);
        header_count++;
        free(body);
    }
    
    // static storage for first line of http response
    char http[MAX_HEADERS] = "HTTP/1.1";
    char httpc_nf[MAX_HDR_LEN] = "404";                 // httpc(ode)_n(ot)f(ound)
    char httpc_ni[MAX_HDR_LEN] = "501";                 // httpc(ode)_n(ot)i(mplemented)
    char httpc_ok[MAX_HDR_LEN] = "200";                 // httpc(ode)_ok
    char httpl_nf[MAX_HDR_LEN] = "Not Found";           // httpl(abel)_n(ot)f(ound)
    char httpl_ni[MAX_HDR_LEN] = "Not Implemented";     // httpl(abel)_n(ot)i(mplemented)
    char httpl_ok[MAX_HDR_LEN] = "OK";                  // httpl(abel)_ok
    char ctype[MAX_HEADERS] = "text/html";
    char clang[MAX_HEADERS] = "en-US";

    // FILE *file;
    char tempCon[256];
    char* buffer_content = fretrvs_replacement(uri);

    // handle case for code 501
    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        fprintf(output, "%s %s %s\r\n", http, httpc_ni, httpl_ni);
        fprintf(output, "Content-Type: %s\r\n", ctype);
        fprintf(output, "Content-Language: %s\r\n", clang);
        fprintf(output, "Content-Length: 0\r\n\r\n");
        // fprintf(output, "<html>\n\t<body>\n\t\t501 Not Implemented - Your request method is not supported by the server. Try GET or POST\n\t</body>\n</html>\n\n");
        fprintf(stderr, "Request Method: %s\n", method);
        fprintf(stderr, "Request URI: %s\n", uri);
        fprintf(stderr, "Request Version: %s\n", version);
        fprintf(stderr, "Request Headers:\n");
        header_printer(headers, header_count);
        fflush(output);
        //system("firefox 501.html &"); // call system exec firefox to the url "501.html", & used to send process to background
        return;
    }

    // if fretrvs did not return null, handle cases for codes 200 with either "GET" or "POST"
    if (buffer_content) {
        if (strcmp(method, "GET") == 0) {
            fprintf(output, "%s %s %s\r\n", http, httpc_ok, httpl_ok);
            fprintf(output, "Content-Type: %s\r\n", ctype);
            fprintf(output, "Content-Language: %s\r\n", clang);
            fprintf(output, "Content-Length: %lu\r\n", strlen(buffer_content));
            fprintf(output, "\r\n");
            fprintf(output, "%s", buffer_content);
            // puts(buffer_content);
            fflush(output);
        } else if (strcmp(method, "POST") == 0) {
            fprintf(output, "%s %s %s\r\n", http, httpc_ok, httpl_ok);
            fprintf(output, "Content-Type: %s\r\n", ctype);
            fprintf(output, "Content-Language: %s\r\n", clang);
            fprintf(output, "Content-Length: %lu\r\n", strlen(buffer_content));
            fprintf(output, "\r\n");
            fprintf(output, "%s", buffer_content);
            // puts(buffer_content);
            fflush(output);
        }
    // if fretrvs did return null, assume code 404
    } else {
        fprintf(output, "%s %s %s\r\n", http, httpc_nf, httpl_nf);
        fprintf(output, "Content-Type: %s\r\n", ctype);
        fprintf(output, "Content-Language: %s\r\n", clang);
        fprintf(output, "Content-Length: 0\r\n");
        fprintf(output, "\r\n");
        // fprintf(output, "<html>\n\t<body>\n\t\t404 Not Found - The server cannot find your requested resource. Check the url!\n\t</body>\n</html>\n\n");
        fflush(output);
    }
    
    // basic printing before offloading header array for formatting and printing
    fprintf(stderr, "Request Method: %s\n", method);
    fprintf(stderr, "Request URI: %s\n", uri);
    fprintf(stderr, "Request Version: %s\n", version);
    fprintf(stderr, "Request Headers:\n");
    header_printer(headers, header_count);

    fflush(output);
}

// +----------------+
// | header_printer |
// +----------------+
// create constant string set to post content header and init delay index. this skips the possible printing of "POST Content:", if it exists, to comply with AG formatting.
// use variable pad to get the length of the first format specifier, the header in this case, and add four to it to get proper alignment in output to stderr. then, if there is a 
// post content header, print it and its value to a newline (stderr)
void header_printer(char headers[][PAIR][MAX_HDR_LEN], int header_count) {
    const char *delay_post = "POST Content: ";
    int delay_index = -1;
    for (int i = 0; i < header_count; i++) {
        if (strcmp(headers[i][0], delay_post) == 0) {
            delay_index = i;
            continue;
        }
        int pad = 0;
        pad += (strlen(headers[i][0]) + 4);
        fprintf(stderr, "%*s --> %s\n", pad, headers[i][0], headers[i][1]);
    }

    if (delay_index != -1) {
        fprintf(stderr, "%s%s\n", headers[delay_index][0], headers[delay_index][1]);
    }
}

// +---------------+
// | header_lookup |
// +---------------+
// did not use but could serve helpful if using a list of headers to search for
char header_lookup(char headers[][PAIR][MAX_HDR_LEN], int header_count, char hdr[], char hdrval[]) {
    for (int i = 0; i < header_count; i++) {
        if (strcmp(headers[i][0], hdr) == 0) {
            strcpy(hdrval, headers[i][1]);
            return *hdrval;
        }
    }
    return 0;
}




int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <docroot> <port>\n", argv[0]);
        return 1;
    }

    strncpy(docroot, argv[1], MAX_BUFFER - 1);
    int port = atoi(argv[2]);
    printf("Listening on port %d\n", port);

    int pipefd[2];
    int replyfd[2];
    if (pipe(pipefd) == -1 || pipe(replyfd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(replyfd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        close(replyfd[0]);
        close(replyfd[1]);
        execlp("nc", "nc", "-l", "-p", argv[2], NULL);
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        close(pipefd[1]);
        close(replyfd[0]);
        char filename[64];
        snprintf(filename, sizeof(filename), "request");
        FILE* out = fopen(filename, "w");
        FILE* in = fdopen(pipefd[0], "r");
        parse_request(in, out);
        fflush(out);
        fclose(out);
        FILE* reply = fopen(filename, "r");
        char buffer[MAX_BUFFER];
        size_t nread;
        while ((nread = fread(buffer, 1, sizeof(buffer), reply)) > 0) {
            write(replyfd[1], buffer, nread);
        }
        close(replyfd[1]);
        close(pipefd[0]);
        fclose(in);
        fclose(reply);
        wait(NULL);
    }
    return 0;
}



