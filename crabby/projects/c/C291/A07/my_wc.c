/*
Programmer: Charles Moye

Program may be utilized with ./my_wc [options] < FILE
First the options will be parsed and the file will begin processing. Words will be added to the structure, and the capacity of words will scale with the length of the text, meaning
if the file will exceed 40 bytes, the buffer will increment, same with the words. Finally, as per the user's instructions the respective functions will output their findings to the
user.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define INIT_BUFFER_SIZE 40
#define WORD_LIST_INCR 5

/* create structure to hold information about the words weve seen */
typedef struct {
    char *word;
    int count;
} word_info;

// Globals
int line_count = 0, word_count = 0, char_count = 0;
int debug_mode = 0; // enable if -d
word_info *word_list = NULL;
int word_list_size = 0, word_list_capacity = 5;

// Prototypes
void process_input();
void add_word(const char *word);
void print_counts(int print_lines, int print_words, int print_chars, int print_freq);
void free_memory();
void print_help();

/* main: determine the parts of the program the user would like to utilize (or choose for them) 
 * allocate initial memory to store information about the words
 * call functions to process the file and print results, and then free the mem*/
int main(int argc, char *argv[])
{
    // use getopt to gather options from command line and enable the variables pertaining to the user's options
    int opt;
    int print_lines = 0, print_words = 0, print_chars = 0, print_freq = 0;

    while ((opt = getopt(argc, argv, "lcwfvhd")) != -1) {
        switch(opt) {
            case 'l': print_lines = 1; break;
            case 'c': print_chars = 1; break;
            case 'w': print_words = 1; break;
            case 'f': print_freq = 1; break;
            case 'v': print_lines = print_chars = print_words = print_freq = 1; break;
            case 'h': print_help(); return 0; 
            case 'd': debug_mode = 1; break;
            default:
                fprintf(stderr, "Invalid option. Use -h for help\n");
                return 1;
        }
    }

    // -lcw default
    if (!print_lines && !print_words && !print_chars && !print_freq) {
        print_lines = print_words = print_chars = 1;
    }

    // alloc initial mem for wordlist
    word_list = malloc(word_list_capacity * sizeof(word_info));
    if (!word_list) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1;
    }

    process_input();
    print_counts(print_lines, print_words, print_chars, print_freq);
    free_memory();

    return 0;
}
/* process_input: gather all the information we can from the file */
void process_input() {
    char *buffer = malloc(INIT_BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }

    int buffer_size = INIT_BUFFER_SIZE;
    int index = 0;
    char word[128];
    int word_index = 0;
    int in_word = 0;
    
    // iterate until we find EOF
    while (1) {
        int ch = getchar();
        if (ch == EOF) break;

        char_count++;
        // increment line count when newline character discovered
        if (ch == '\n') line_count++;
        
        // when we feel the buffer getting a little too close to its maximum, give it some more mem
        if (index >= buffer_size - 1) {
            buffer_size += INIT_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);
            if (!buffer) {
                fprintf(stderr, "Error: Memory reallocation failed\n");
                exit(1);
            }
            if (debug_mode) fprintf(stderr, "DEBUG    Expanded buffer to %d bytes\n", buffer_size);
        }

        buffer[index++] = ch;
        buffer[index] = '\0';
        
        // trust that a space is the only thing dividing up the words...
        if (isspace(ch)) {
            if (in_word) {
                word[word_index] = '\0';
                add_word(word);
                word_index = 0;
                word_count++;
            }
            in_word = 0;
        } else {
            if (word_index < sizeof(word) - 1) {
                word[word_index++] = ch;
            }
            in_word = 1;
        }
    }
    // be free
    free(buffer);
}

// Adds a word to the dynamic word list or increments count if it exists
void add_word(const char *word) {
    // Check if word exists
    for (int i = 0; i < word_list_size; i++) {
        if (strcmp(word_list[i].word, word) == 0) {
            word_list[i].count++;
            return;
        }
    }

    // New word, add to list. Just as before, give it some more mem when it starts creeping up...
    if (word_list_size >= word_list_capacity) {
        word_list_capacity += WORD_LIST_INCR;
        word_list = realloc(word_list, word_list_capacity * sizeof(word_info));
        if (!word_list) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            exit(1);
        }
        if (debug_mode) fprintf(stderr, "DEBUG    Expanded word list to %d words.\n", word_list_capacity);
    }
    // dupe the word despite the AG's concern
    word_list[word_list_size].word = strdup(word);
    word_list[word_list_size].count = 1;
    word_list_size++;

    if (debug_mode) fprintf(stderr, "DEBUG    New word found: %s\n", word);
}

// Prints the requested output
void print_counts(int print_lines, int print_words, int print_chars, int print_freq) {
    if (print_lines) printf("\nline count : %d\n", line_count);
    if (print_words) printf("word count : %d\n", word_count);
    if (print_chars) printf("char count : %d\n", char_count);
    if (print_freq) {
        printf("word frequency :\n");
        for (int i = 0; i < word_list_size; i++) {
            printf("%s%s : %d\n", "    ", word_list[i].word, word_list[i].count);
        }
    }
}

// Frees all dynamically allocated memory
void free_memory() {
    for (int i = 0; i < word_list_size; i++) {
        free(word_list[i].word);
    }
    free(word_list);
}

// Prints program usage, took forever...
void print_help() {
    //printf("Usage: my_wc.o [options] < input.txt\n");
    //printf("Options:\n");
    printf("Prints the word count from stdin.\n");
    printf("Usage: my_wc [-h] [-l] [-c] [-w] [-f] [-d] [-v] [-a] [-p]\n");
    printf("-h -- display this help message\n");
    printf("-d -- debugging output to stderr\n");
    printf("-w -- word count (default with no options)\n");
    printf("-c -- character count\n");
    printf("-l -- line count\n");
    printf("-f -- word frequency\n");
    printf("-v -- output all word, line, character. and frequency\n");
    printf("-a -- report average word and line length\n");
    printf("-p -- do not include punctuation in words\n");
    /*
    printf("-l -- Report line count\n");
    printf("-c -- Report character count\n");
    printf("-w -- Report word count\n");
    printf("-f -- Report frequency of each unique word\n");
    printf("-v -- Verbose mode (equivalent to -l -c -w -f)\n");
    printf("-h -- Print this help message\n");
    printf("-d -- Debugging mode (prints debug info to stderr)\n"); */
}





