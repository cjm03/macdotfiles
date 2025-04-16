#include <stdio.h>

#define START 0

int main()
{
    int c, nl, bl, tab;
    
    nl = START;
    bl = START;
    tab = START;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        if (c == '\t') {
            ++tab;
        }
        if (c == ' ') {
            ++bl;
        }
    }
    printf("newlines: %d\n", nl);
    printf("spaces: %d\n", bl);
    printf("tabs: %d\n", tab);
}
