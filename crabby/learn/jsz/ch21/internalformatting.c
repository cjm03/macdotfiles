#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int bufSize = 80;

int main(void)
{
    int anInt = -1;
    double aDouble = -1.0;
    int numScanned = 0, numPrinted = 0;
    char sIn[] = "1234 5678.9012";
    char sOut[bufSize];
    memset(sOut, 0, bufSize);

    printf("Using sscanf() on [%s]\n", sIn);
    numScanned = sscanf(sIn, "%d%lf", &anInt, &aDouble);
    printf("sscanf() assigned %d values\n", numScanned);
    printf("1. int: %d\n", anInt);
    printf("2. double: %lf\n\n", aDouble);
    puts("Using sprintf() to format values to string buffer:");
    numPrinted = sprintf(sOut, "integer=[%d] double=[%9.4lf]",
                         anInt, aDouble);
    printf("%d characters in output string \"%s\"\n",
           numPrinted, sOut);
}
