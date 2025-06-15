/* 
 * httpd.c (Modified for Assignment 09)
 *
 * Programmer: Charles Moye 
 *
 * This version uses fork/exec to launch netcat on a given port, processes HTTP requests via pipes,
 * implements its own version of fretrvs(), and provides directory listings for directory URIs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_REQ_LINE 1024
#define MAX_HEADER_LINE 1024
#define MAX_PATH 4096

char document_root[MAX_PATH];

// Function to retrieve file content
char* get_file_content(const char* uri) {
    static char buffer[10000];
    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "%s%s", document_root, uri);

    struct stat st;
    if (stat(path, &st) == -1) return NULL;

    if (S_ISDIR(st.st_mode)) {
        DIR* dir = opendir(path);
        if (!dir) return NULL;

        struct dirent* entry;
        static char html[10000];
        snprintf(html, sizeof(html), "<HTML>\n<BODY>\n<TABLE>\n");

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            char fullpath[MAX_PATH];
            snprintf(fullpath, MAX_PATH, "%s/%s", path, entry->d_name);

            stat(fullpath, &st);
            if (S_ISDIR(st.st_mode)) {
                snprintf(buffer, sizeof(buffer), "<TR><TD>%s/</TD><TD>-- bytes</TD></TR>\n", entry->d_name);
            } else {
                snprintf(buffer, sizeof(buffer), "<TR><TD>%s</TD><TD>%ld bytes</TD></TR>\n", entry->d_name, st.st_size);
            }
            strncat(html, buffer, sizeof(html) - strlen(html) - 1);
        }
        closedir(dir);
        strncat(html, "</TABLE>\n</BODY>\n</HTML>\n", sizeof(html) - strlen(html) - 1);
        return html;
    } else {
        FILE* file = fopen(path, "r");
        if (!file) return NULL;
        size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, file);
        buffer[bytes_read] = '\0';
        fclose(file);
        return buffer;
    }
}

// Parse and process a request
void process_request(FILE* input, FILE* output) {
    char method[8], uri[1024], version[16];
    char line[MAX_REQ_LINE];
    if (!fgets(line, sizeof(line), input)) return;

    sscanf(line, "%s %s %s", method, uri, version);
    fprintf(stderr, "method: %s\nuri: %s\nversion: %s\n", method, uri, version);

    while (fgets(line, sizeof(line), input) && strcmp(line, "\r\n") != 0) {
        fprintf(stderr, "header: %s", line);
    }

    char* content = get_file_content(uri);
    if (content) {
        fprintf(output, "%s 200 OK\r\nContent-Length: %ld\r\n\r\n%s", version, strlen(content), content);
    } else {
        const char* not_found = "<HTML><BODY>404 Not Found</BODY></HTML>";
        fprintf(output, "%s 404 Not Found\r\nContent-Length: %ld\r\n\r\n%s", version, strlen(not_found), not_found);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <documentroot> <port>\n", argv[0]);
        exit(1);
    }

    strncpy(document_root, argv[1], MAX_PATH - 1);
    int port = atoi(argv[2]);
    printf("Listening on port %d\n", port);

    int to_child[2], from_child[2];
    pipe(to_child);
    pipe(from_child);

    pid_t pid = fork();
    if (pid == 0) {
        dup2(to_child[0], STDIN_FILENO);
        dup2(from_child[1], STDOUT_FILENO);
        close(to_child[1]); close(from_child[0]);
        execlp("nc", "nc", "-l", "-p", argv[2], NULL);
        perror("exec failed");
        exit(1);
    } else {
        close(to_child[0]); close(from_child[1]);
        FILE* in = fdopen(from_child[0], "r");
        FILE* out = fdopen(to_child[1], "w");
        process_request(in, out);
        fclose(in); fclose(out);
        wait(NULL);
    }
    return 0;
}
