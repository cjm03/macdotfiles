#include <stdio.h>

int main(void)
{
    int anInt = -1;
    double aDouble = -1.0;
    int numScanned = 0;

    printf("Enter an integer and a decimal number: ");
    numScanned = scanf("%d%lf", &anInt, &aDouble);
    printf("scanf() was able to assign %d values\n", numScanned);
    if (numScanned > 0) printf("1. integer: %d\n", anInt);
    if (numScanned > 1) printf("2. double: %lf\n", aDouble);
    printf("\n");
}
