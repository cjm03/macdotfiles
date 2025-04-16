#include <stdio.h>

int power1(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; i++) {
        p = p * base;
    }
    return p;
}

int power2(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n) {
        p = p * base;
    }
    return p;
}
