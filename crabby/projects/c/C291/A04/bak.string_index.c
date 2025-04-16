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
void fill_buffer(char* buffer);
void index_buffer(char* buffer, int indexarr[INDEX_SIZE][3], int* word_count);
int word_existence(char* word, char buffer[BUFFER_SIZE], int indexarr[INDEX_SIZE][3], int word_count);







/*
    functions
*/
// Function to fill the buffer initialized in main with the input from stdin
void fill_buffer(char* buffer) {
      int counter = 0;
      char c;
      while ((c = getchar()) != EOF) {                       // if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
          buffer[counter++] = c;                             //     fprintf(stderr, "error reading input to buffer\n");
                                                             // }
          if (counter >= BUFFER_SIZE)
              break;
      }

    //    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
    //        fprintf(stderr, "Error reading input to buffer\n");
    //    }

}

// Function to index buffer
void index_buffer(char* buffer, int indexarr[INDEX_SIZE][3], int *word_count) {
    int offset_index = 0;
    char word[BUFFER_SIZE];
    int word_length = 0;

    for (int i = 0; i < BUFFER_SIZE && buffer[i] != '\0'; i++) {
        if (!isspace(buffer[i])) {
            word[word_length++] = buffer[i];
        } else if (word_length > 0) {
            word[word_length] = '\0';
            offset_index = i - word_length;

            // check if word already present in 2d array
            int existence = word_existence(word, buffer, indexarr, *word_count);
            if (existence == -1) {
                indexarr[*word_count][0] = offset_index;
                indexarr[*word_count][1] = word_length;
                indexarr[*word_count][2] = 1;
                (*word_count)++;
            } else {
                indexarr[existence][2]++;
            }
            word_length = 0;
        }
    }
}

// Function to support indexing and return true or false if passed word exists in the 2d index array
int word_existence(char* word, char buffer[BUFFER_SIZE], int indexarr[INDEX_SIZE][3], int word_count) {
    char temp[BUFFER_SIZE];
    for (int i = 0; i < word_count; i++) {
        for (int j = indexarr[i][0]; j < (indexarr[i][0] + indexarr[i][1]); j++) {
            temp[j] = buffer[j]
            if (strcmp(word, &buffer[indexarr[i][0]]) == 0) {
                return i;
            }
        }    
    } 
    return -1;
} 


void print_report(char buffer[BUFFER_SIZE], int indexarr[INDEX_SIZE][3], int word_count) { 
    int total_words = 0;
    printf("\n%-10s %-10s %-10s %-10s\n", "BEGIN", "LENGTH", "COUNT", "WORD");
    for (int i = 0; i < word_count; i++) {
        total_words += indexarr[i][2];
        while (int j = (indexarr[i][0] + indexarr[i][1]) {
            printf("%-10d %-10d %-10d %s\n", indexarr[i][0], indexarr[i][1], indexarr[i][2], &buffer[indexarr[i][0]]);
        }
    }
    printf("Total bytes processed: \n"); // TODO 
    printf("Total Unique Words: %d\n", word_count); // TODO

    printf("Total words found: %d\n", total_words); // TODO
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

    // call fill_buffer to populate buffer
    fill_buffer(buffer);
    // call function to index buffer
    index_buffer(buffer, indexarr, &word_count);
    // call function to emit report
    print_report(buffer, indexarr, word_count);
    // printf("\n%s", buffer);
    // printf("\n%lu", sizeof(buffer)); 
    return 0;
}




