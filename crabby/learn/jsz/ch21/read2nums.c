#include <stdio.h>

int main(void)
{
    int anInt = -1;
    double aDouble = -1.0;
    printf("Enter an integer and a decimal number: ");
    scanf("%d%lf", &anInt, &aDouble);
    printf("1. integer: %d\n", anInt);
    printf("2. double: %lf\n", aDouble);
}
