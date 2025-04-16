/*
string_ind.c

Programmer: Charles Moye


*/

/*
    includes
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    defines
*/
#define BUFFER_SIZE 2048 // constant buffer size
#define INDEX_SIZE (BUFFER_SIZE / 2) // constant max words to index (exercises/wk06/demo_a04.c)
#define TEST_STRING "All the men and all the women in all the world." // test 

/*
    prototypes
*/
void fill_buffer(char* buffer, int *buf_counter);
void index_buffer(char* buffer, int indexarr[INDEX_SIZE][3], int *word_count);
int find_word_index(char *buffer, int indexarr[INDEX_SIZE][3], int word_count, char *word, int word_len);






/*
    functions
*/
// Function to fill the buffer initialized in main with the input from stdin
void fill_buffer(char* buffer, int *buf_counter) {
      int counter = *buf_counter;
      char c;
      while ((c = getchar()) != EOF) {                       // if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
          buffer[counter++] = c;                             //     fprintf(stderr, "error reading input to buffer\n");
                                                             // }
          if (counter >= BUFFER_SIZE)
              break;
      }
      *buf_counter = counter;


}

// Function to index buffer
void index_buffer(char* buffer, int indexarr[INDEX_SIZE][3], int *word_count) {
    int start = 0;
    int wc = *word_count;
    int buffer_len = strlen(buffer);

    for (int i = 0; i <= buffer_len; i++) {
        if (isspace(buffer[i]) || buffer[i] == '\0') {
            if (i > start) {
                buffer[i] = '\0';

                int word_len = i - start;
                int existing_index = find_word_index(buffer, indexarr, wc, &buffer[start], word_len);

                if (existing_index == -1) {
                    if (wc < INDEX_SIZE) {
                        indexarr[wc][0] = start;
                        indexarr[wc][1] = word_len;
                        indexarr[wc][2] = 1;
                        wc++;
                    }
                } else {
                    indexarr[existing_index][2]++;
                }
            }
            start = i + 1;
        }
    }

    *word_count = wc;
}

// Function to support indexing and return true or false if passed word exists in the 2d index array
int find_word_index(char *buffer, int indexarr[INDEX_SIZE][3], int word_count, char *word, int word_len) {
    for (int i = 0; i < word_count; i++) {
        int start = indexarr[i][0];
        int length = indexarr[i][1];

        // Compare word with existing indexed word
        if (length == word_len && strncmp(&buffer[start], word, word_len) == 0) {
            return i;  // Word already exists, return index
        }
    }
    return -1;  // Word not found
}


void print_report(char *buffer, int indexarr[INDEX_SIZE][3], int word_count, int buf_counter) { 
    int not_unique = 0;
    printf("\n%-10s %-10s %-10s %-10s\n", "BEGIN", "LENGTH", "COUNT", "WORD");
    for (int i = 0; i < (word_count - 1); i++) {
        char word[256];
        not_unique += indexarr[i][2];
        strncpy(word, &buffer[indexarr[i][0]], indexarr[i][1]);
        word[indexarr[i][1]] = '\0';

        printf("%-10d %-10d %-10d %s\n", indexarr[i][0], indexarr[i][1], indexarr[i][2], &buffer[indexarr[i][0]]);
    }
    printf("Total bytes processed: %d\n", buf_counter); // TODO 
    printf("Total Unique Words: %d\n", word_count - 1); // TODO
    printf("Total words found: %d\n", not_unique); // TODO
} 

int main(void) {
    // declare buffer of size 2048 using initially declared variable BUFFER_SIZE
    char buffer[BUFFER_SIZE];
    // declare 2D indexing array to store offset index, length, and count values for up to 1024 unique strings.
    // string representation of each word should be referenced by using the offset index value in column 0 of each row.
    int indexarr[INDEX_SIZE][3];
    // declare variable to store word count
    int word_count;
    word_count = 0;
    // declare variable to store # of characters in buffer
    int buf_counter;
    buf_counter = 0;
    // call fill_buffer to populate buffer
    fill_buffer(buffer, &buf_counter);
    // call function to index buffer
    index_buffer(buffer, indexarr, &word_count);
    // call function to emit report
    print_report(buffer, indexarr, word_count, buf_counter);
    // printf("\n%s", buffer);
    // printf("\n%lu", sizeof(buffer)); 
    return 0;
}




