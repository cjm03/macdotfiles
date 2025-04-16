#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 2048


typedef struct {
    int start;
    int length;
    int count;
} WordIndex;

void populate_buffer(char *buffer, int *bytes_read) {
    *bytes_read = fread(buffer, 1, BUFFER_SIZE, stdin);
}

int index_buffer(const char *buffer, int bytes_read, WordIndex *index_array, int *unique_words) {
    int i = 0, word_count = 0;
    while (i < bytes_read) {
        while (i < bytes_read && !isalpha(buffer[i])) i++; // Skip non-alphabetic characters
        if (i >= bytes_read) break;

        int start = i;
        while (i < bytes_read && isalpha(buffer[i])) i++; // Read word
        int length = i - start;

        // Search if word already exists in index
        int found = 0;
        for (int j = 0; j < word_count; j++) {
            if (index_array[j].length == length && strncmp(&buffer[index_array[j].start], &buffer[start], length) == 0) {
                index_array[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            index_array[word_count].start = start;
            index_array[word_count].length = length;
            index_array[word_count].count = 1;
            word_count++;
        }
    }
    *unique_words = word_count;
    return i;
}

void emit_report(const char *buffer, const WordIndex *index_array, int unique_words, int total_bytes) {
    printf("BEGIN     LENGTH    COUNT     WORD\n");
    int total_words = 0;
    for (int i = 0; i < unique_words; i++) {
        total_words += index_array[i].count;
        printf("%-9d %-9d %-9d %.*s\n", index_array[i].start, index_array[i].length, index_array[i].count, index_array[i].length, &buffer[index_array[i].start]);
    }
    printf("Total bytes processed: %d\n", total_bytes);
    printf("Total Unique Words: %d\n", unique_words);
    printf("Total words found: %d\n", total_words);
}

int main(void) {
    char buffer[BUFFER_SIZE] = {0};
    WordIndex index_array[BUFFER_SIZE] = {0};
    int bytes_read = 0, unique_words = 0;

    populate_buffer(buffer, &bytes_read);
    int total_bytes = index_buffer(buffer, bytes_read, index_array, &unique_words);
    emit_report(buffer, index_array, unique_words, total_bytes);

    return 0;
}
