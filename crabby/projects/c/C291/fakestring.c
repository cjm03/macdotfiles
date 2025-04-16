#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 2048
#define MAX_WORDS 1000

// Function to check if a word exists in the 2D array
int word_exists(char *word, char buffer[], int word_data[MAX_WORDS][3], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, &buffer[word_data[i][0]]) == 0) {
            return i;  // Word found, return its index
        }
    }
    return -1;  // Word not found
}

// Function to read input and extract words with their offset, length, and frequency
void read_input_and_extract_words(char* buffer, int word_data[MAX_WORDS][3], int* word_count) {
    int offset_index = 0;
    char word[BUFFER_SIZE];
    int word_len = 0;

    for (int i = 0; i < BUFFER_SIZE && buffer[i] != '\0'; i++) {
        // Skip non-alphabetical characters (they're considered delimiters)
        if (isalpha(buffer[i])) {
            word[word_len++] = buffer[i];
        } else if (word_len > 0) {
            word[word_len] = '\0';  // Null-terminate the word

            // Check if the word already exists in the 2D array
            int index = word_exists(word, buffer, word_data, *word_count);

            if (index == -1) {
                // Word doesn't exist, add a new entry
                word_data[*word_count][0] = offset_index;  // Store the offset
                word_data[*word_count][1] = word_len;     // Store the length
                word_data[*word_count][2] = 1;            // Set count to 1
                (*word_count)++;
            } else {
                // Word exists, increment the count
                word_data[index][2]++;
            }

            // Reset word buffer and length for the next word
            word_len = 0;
        }
        // Update offset (only for words, not for delimiters)
        if (word_len > 0 || isalpha(buffer[i])) {
            offset_index++;
        }
    }
}

int main() {
    char buffer[BUFFER_SIZE];  // Declare buffer to hold input
    int word_data[MAX_WORDS][3];  // 2D array to store offset, length, and count
    int word_count = 0;

    printf("Enter a string: ");
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Extract words from the buffer and store their details
    read_input_and_extract_words(buffer, word_data, &word_count);

    // Output the details of the words
    printf("\nUnique words in the buffer:\n");
    for (int i = 0; i < word_count; i++) {
        printf("Word: \"%.*s\", Offset: %d, Length: %d, Count: %d\n",
               word_data[i][1], &buffer[word_data[i][0]], word_data[i][0], word_data[i][1], word_data[i][2]);
    }

    return 0;
}
