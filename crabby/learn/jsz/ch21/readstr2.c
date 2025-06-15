#include <stdio.h>

const int bufSize = 80;

int main(void)
{
    char strBuf[bufSize];
    printf("enter your string: ");
    gets(strBuf);
    puts("You entered:");
    puts(strBuf);
}
