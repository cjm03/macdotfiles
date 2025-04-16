#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include <ctype.h>
/* informUsage: inform user of usage */
void informUsage(char* cmd)
{
    fprintf(stderr, "usage: %s inputFilename\n", cmd);
    exit(0);
}

int main(int argc, char *argv[])
{
    // initialize input file and save its name
    FILE* inputFile = NULL;
    char* inputFilename = argv[1];
    // make sure user has passed filename
    if (argc != 2) {
        informUsage(argv[0]);
    }
    // verify user's file is not empty
    if (NULL == (inputFile = fopen(argv[1], "r"))) {
        fprintf(stderr, "input file: %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }
    // hope user filename is less than 75 characters
    char outputFilename[80];
    // create new file with same name + "-flip"
    snprintf(outputFilename, sizeof(outputFilename), "%s-flip", inputFilename);
    // open
    FILE* outputFile = fopen(outputFilename, "w");
    // verify
    if (outputFile == NULL) {
        fprintf(stderr, "unable to open new file");
        exit(1);
    }

    // iterate through users file character by character
    // if character is lowercase, write to new file in uppercase
    // if character is uppercase, write to new file in lowercase
    // otherwise, write to new file as is
    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (isupper(c)) {
            fputc(tolower(c), outputFile);
        } else if (islower(c)) {
            fputc(toupper(c), outputFile);
        } else {
            fputc(c, outputFile);
        }
    }
    // close the files
    fclose(inputFile);
    fclose(outputFile);
    return 0;

}
