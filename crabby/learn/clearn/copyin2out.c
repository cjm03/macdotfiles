#include <stdio.h>

int main()
{
    /*              works, but lacks conciseness
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    */

    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
