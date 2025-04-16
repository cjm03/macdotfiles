/*
*
*/
/*    include    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "fretrv.h"
#include "httpd.h"


/*    functions    */

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

    //fprintf(stderr, "Method: %s\n", method);
    //fprintf(stderr, "URI: %s\n", uri);
    //fprintf(stderr, "Version: %s\n", version);

    while (fgets(line, sizeof(line), input) != 0) {
        char header[MAX_HDR_LEN], value[MAX_HDR_LEN];
        if (sscanf(line, "%[^:]: %[^\r\n]", header, value) == 2) {
            strncpy(headers[header_count][0], header, MAX_HDR_LEN - 1);
            strncpy(headers[header_count][1], value, MAX_HDR_LEN - 1);
//          fprintf(stderr, "%s: %s\n", headers[header_count][0], headers[header_count][1]);
            header_count++;
        } else if (sscanf(line, "%[^\r\n]", value) == 1) {
            strncpy(headers[header_count][0], "POST Content: ", MAX_HDR_LEN - 1);
            strncpy(headers[header_count][1], value, MAX_HDR_LEN - 1);
            header_count++;
        }
        // Need to use sscanf to gather "header:" "value" format
        // Header should end with colon, value should end with space? newline? <CR>?
        // Regex?  questionable: "%([\w-]+):\s %([\w./-]+)"
        // Also account for POST content, ie: color=blue
        // Headers will come in, then there will be a newline, and then after the newline
        // is where the POST content will lie.
    }

    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        fprintf(stderr, "HTTP/1.1 501 Not Implemented\n");
        fprintf(stderr, "Content-Type: text/html\n");
        fprintf(stderr, "Content-Language: en-US\n");
        fprintf(stderr, "Content-Length: 0\n");
//        return;
    }

/*    char divert_fretrv_output[MAX_BUFFER];
    setvbuf(stderr, divert_fretrv_output, _IOFBF, sizeof(divert_fretrv_output));
    int found = (fretrvs(buffer_content, 1024, uri) != NULL);
    setvbuf(stderr, NULL, _IONBF, 0);*/
    
    int orig_stdout = dup(STDOUT_FILENO);
    int orig_stderr = dup(STDERR_FILENO);
    int devnull = open("/dev/null", O_WRONLY);
    dup2(devnull, STDOUT_FILENO);
    dup2(devnull, STDERR_FILENO);
    close(devnull);
    int found = (fretrvs(buffer_content, 1024, uri) != NULL);
    dup2(orig_stdout, STDOUT_FILENO);
    dup2(orig_stderr, STDERR_FILENO);
    close(orig_stdout);
    close(orig_stderr);

    //if (fretrvs(buffer_content, 1024, uri) != NULL) {
    if (found) {
        if (strcmp(method, "GET") == 0) {
            fprintf(stderr, "HTTP/1.1 200 OK\n");
            fprintf(stderr, "Content-Type: text/html\n");
            fprintf(stderr, "Content-Language: en-US\n");
            fprintf(stderr, "Content-Length: %lu\n\n", strlen(buffer_content));
            puts(buffer_content);
        } else if (strcmp(method, "POST") == 0) {
            fprintf(stderr, "HTTP/1.1 200 OK\n");
            fprintf(stderr, "Content-Type: text/html\n");
            fprintf(stderr, "Content-Language: en-US\n");
            fprintf(stderr, "Content-Length: %lu\n\n", strlen(buffer_content));
            puts(buffer_content);
        }
    } else {
        fprintf(stderr, "HTTP/1.1 404 Not Found\n");
        fprintf(stderr, "Content-Type: text/html\n");
        fprintf(stderr, "Content-Language: en-US\n");
        fprintf(stderr, "Content-Length: 0\n\n");
        puts(buffer_content);
//        return;
    }

    fprintf(stderr, "Request Method: %s\n", method);
    fprintf(stderr, "Request URI: %s\n", uri);
    fprintf(stderr, "Request Version: %s\n", version);
    fprintf(stderr, "Request Headers:\n");
    header_printer(headers, header_count);
}

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
    parse_request(stdin);
    return 0;
}
