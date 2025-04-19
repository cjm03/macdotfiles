#include <stdio.h>

void showChar(int ch);

int main(void)
{
    signed char aChar = 'A';
    char c1 = 65;
    char c2 = 'a';
    char c3 = 97;
    char c4 = '1';
    unsigned char aByte = 1;

    showChar(aChar);
    showChar(c1);
    showChar(c2);
    showChar(c3);
    showChar(c4);
    showChar(aByte);
}

void showChar(int ch)
{
    printf("ch = '%c' (%d) [%#x]\n", ch, ch, ch);
}
