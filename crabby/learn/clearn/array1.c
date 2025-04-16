#include <stdio.h>

int main()
{
    // c to store character
    // i to store loop counters
    // nwhite to store number of whitespace occurrences
    // nother to store number of other characters
    // ndigit to store number of occurrences of each digit in an array
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;                // initialize nwhite and nother to zero
    for (i = 0; i < 10; i++) {          // populate ndigit array with each digit and start val. 0
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {                        // loop until EOF received
        if (c >= '0' && c <= '9') {                         // check c's ASCII value for 0-9
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {    // check for whitespace
            ++nwhite;
        } else {                                            // otherwise incr. nother
            ++nother;
        }
    }
/*          Histogram Output          */
    for (i = 0; i < 10; i++) {
        printf("[%d] ", i);
        for (int j = 0; j < ndigit[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    /*                      Original Program Output
    printf("digits =");
    for (i = 0; i < 10; i++) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
    */
}
