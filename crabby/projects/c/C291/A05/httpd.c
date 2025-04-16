/* 
 * httpd.c
 *
 * Programmer: Charles Moye
 *
 * Basic flow: users runs program with a file containing http requests, program parses the requests and returns the response code, response headers, uri content if it exists,
 * request method, uri, and version, and the request headers. response will be stdout, info will be to stderr.
*/


/*    include    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* calling fretrvs() produces output in terminal, researched how to divert stdout & stderr to pass AG tests 1, 2, 3, 4, 10 */
#include <fcntl.h>  /* ^^^^^ */
#include "fretrv.h"
#include "httpd.h"


/*    functions    */

// +---------------+
// | parse_request |
// +---------------+
// takes a file provided from stdin and expects http requests. scans first line searching for method, uri, and version, stores them and scans the rest of the lines searching for
// header:value pairs to add to the headers[][][] array. passes uri to fretrvs() and stores it in int found. checks if the code is 501, and ends after printing necessary info.
// then checks if found holds data, if so checks for get or post method and prints relevant info, if not, assume code 404 and print relevant info.

void parse_request(FILE *input) {
    char line[MAX_LINE_LEN];
    char method[MAX_HDR_LEN], uri[MAX_HDR_LEN], version[MAX_HDR_LEN];
    char headers[MAX_HEADERS][PAIR][MAX_HDR_LEN];
    int header_count = 0;
    char buffer_content[MAX_BUFFER];

    if (!fgets(line, sizeof(line), input)) {
        fprintf(stderr, "Error reading request\n");
        return;
    }

    if (sscanf(line, "%s %s %s", method, uri, version) != 3) {
        fprintf(stderr, "Could not parse request line (%s)\n", line);
        return;
    }
    
    // iterate through each line checking for 2 specific values, if line has 1 specific value declare it as POST Content. store values in header, value, and strncpy to headers array
    while (fgets(line, sizeof(line), input) != 0) {
        char header[MAX_HDR_LEN], value[MAX_HDR_LEN];
        if (sscanf(line, "%[^:]: %[^\r\n]", header, value) == 2) {
            strncpy(headers[header_count][0], header, MAX_HDR_LEN - 1);
            strncpy(headers[header_count][1], value, MAX_HDR_LEN - 1);
            header_count++;
        } else if (sscanf(line, "%[^\r\n]", value) == 1) {
            strncpy(headers[header_count][0], "POST Content: ", MAX_HDR_LEN - 1);
            strncpy(headers[header_count][1], value, MAX_HDR_LEN - 1);
            header_count++;
        }
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

    // modify/redirect stdout and stderr file descriptors before calling fretrvs (storing in found), then return them to how they were
    int orig_stdout = dup(STDOUT_FILENO);
    int orig_stderr = dup(STDERR_FILENO);
    int devnull = open("/dev/null", O_WRONLY);
    dup2(devnull, STDOUT_FILENO);
    dup2(devnull, STDERR_FILENO);
    close(devnull);
    
    FILE *file;
    char tempCon[256];
    int found = (fretrvs(buffer_content, 1024, uri) != NULL);
    // create .html file to execute in browser, doesn't work on autograder 
    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        file = fopen("501.html", "w");
        fprintf(file, "<html>\n\t<body>\n\t\t501 Not Implemented - Your request method is not supported by the server. Try GET or POST\n\t</body>\n</html>");
        fclose(file);
    } 
    // same as ^
    if (!found) {
        file = fopen("404.html", "w");
        fprintf(file, "<html>\n\t<body>\n\t\t404 Not Found - The server cannot find your requested resource. Check the url!\n\t</body>\n</html>");
        fclose(file);
    }

    dup2(orig_stdout, STDOUT_FILENO);
    dup2(orig_stderr, STDERR_FILENO);
    close(orig_stdout);
    close(orig_stderr);
    

    // handle case for code 501
    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        printf("%s %s %s\n", http, httpc_ni, httpl_ni);
        printf("Content-Type: %s\n", ctype);
        printf("Content-Language: %s\n", clang);
        printf("Content-Length: 0\n\n");
        printf("<html>\n\t<body>\n\t\t501 Not Implemented - Your request method is not supported by the server. Try GET or POST\n\t</body>\n</html>\n\n");
        fprintf(stderr, "Request Method: %s\n", method);
        fprintf(stderr, "Request URI: %s\n", uri);
        fprintf(stderr, "Request Version: %s\n", version);
        fprintf(stderr, "Request Headers:\n");
        header_printer(headers, header_count);
        //system("firefox 501.html &"); // call system exec firefox to the url "501.html", & used to send process to background
        return;
    }

    // if fretrvs did not return null, handle cases for codes 200 with either "GET" or "POST"
    if (found) {
        if (strcmp(method, "GET") == 0) {
            printf("%s %s %s\n", http, httpc_ok, httpl_ok);
            printf("Content-Type: %s\n", ctype);
            printf("Content-Language: %s\n", clang);
            printf("Content-Length: %lu\n\n", strlen(buffer_content));
            puts(buffer_content);
        } else if (strcmp(method, "POST") == 0) {
            printf("%s %s %s\n", http, httpc_ok, httpl_ok);
            printf("Content-Type: %s\n", ctype);
            printf("Content-Language: %s\n", clang);
            printf("Content-Length: %lu\n\n", strlen(buffer_content));
            puts(buffer_content);
        }
    // if fretrvs did return null, assume code 404
    } else {
        printf("%s %s %s\n", http, httpc_nf, httpl_nf);
        printf("Content-Type: %s\n", ctype);
        printf("Content-Language: %s\n", clang);
        printf("Content-Length: 0\n\n");
        printf("<html>\n\t<body>\n\t\t404 Not Found - The server cannot find your requested resource. Check the url!\n\t</body>\n</html>\n\n");
        //system("firefox 404.html &"); // call system exec firefox to url 404.html, & used to send process to background
    }
    
    // basic printing before offloading header array for formatting and printing
    fprintf(stderr, "Request Method: %s\n", method);
    fprintf(stderr, "Request URI: %s\n", uri);
    fprintf(stderr, "Request Version: %s\n", version);
    fprintf(stderr, "Request Headers:\n");
    header_printer(headers, header_count);
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




int main() {
    // parse_request() does the heavy lifting
    parse_request(stdin);
    return 0;
}



