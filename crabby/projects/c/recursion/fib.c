#include <stdio.h>

void fib(int first, int second, int n)
{
    if (n < 3) return;
    int next = first + second;
    printf("%d ", next);
    return fib(second, next, n - 1);
}

void printFib(int n)
{
    if (n < 1) {
        printf("Invalid size\n");
    } else if (n == 1) {
        printf("%d ", 0);
    } else if (n == 2) {
        printf("%d %d", 0, 1);
    } else {
        printf("%d %d ", 0, 1);
        fib(0, 1, n);
    }
}

int main(void)
{
    int n = 123;
    printFib(n);
    return 0;
}
