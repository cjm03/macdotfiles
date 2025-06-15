#include <stdio.h>

int main(void)
{
    char aChar;
    int anInt1, anInt2;
    int count;
    printf("1st: Enter <integer><char><integer>: ");
    count = scanf("%d%c%d", &anInt1, &aChar, &anInt2);
    printf("Values scanned = %d. Char selected: [%c]\n",
           count, aChar);
    printf("2nd: Enter <integer> <char> <integer>: ");
    count = scanf("%d %c%d", &anInt1, &aChar, &anInt2);
    printf("Values scanned = %d. Character selected: [%c]\n\n",
           count, aChar);
}
