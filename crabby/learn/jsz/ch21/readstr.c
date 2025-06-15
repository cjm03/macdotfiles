#include <stdio.h>

const int bufSize = 80;

int main(void)
{
    char strBuf[bufSize];
    printf("enter your string: ");
    scanf("%s", strBuf);
    printf("Processed string: [%s]\n", strBuf);
}
