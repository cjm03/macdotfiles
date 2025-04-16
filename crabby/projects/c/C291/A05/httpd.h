#ifndef HTTPD_H
#define HTTPD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_HDR_LEN 256
#define PAIR 2
#define MAX_HEADERS 50
#define MAX_BUFFER 4096

/*    prototypes    */
void parse_request(FILE *input);
void header_printer(char headers[][PAIR][MAX_HDR_LEN], int header_count);
char header_lookup(char headers[][PAIR][MAX_HDR_LEN], int header_count, char hdr[], char hdrval[]);

#endif
