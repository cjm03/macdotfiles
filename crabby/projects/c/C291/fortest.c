#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void tester(char* buffer, int* word_count) {
    int offset_index = 0;
    char word[2048];
    int word_length = 0;

    for (int i = 0; i < 2048 && buffer[i] != '\0'; i++) {
        if (!isspace(buffer[i])) {
            word[word_length++] = buffer[i];
        } else if (word_length > 0) {
            word[word_length] = '\0';
            offset_index = i - word_length;

            printf("Word: %s\tIndex: %d\tLength: %d\n", word, offset_index, word_length);
            printf("i: %d\n\n", i);
            word_length = 0;
            //(*word_count)++;
        }
        
    }
}

int main(void) {
    char buffer[2048] = {"all the "};
    int* word_count = 0;
    tester(buffer, word_count);
    return 0;
}
