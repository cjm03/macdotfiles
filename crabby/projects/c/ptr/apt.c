#include <stdio.h>

int main(void)
{
    int height = 10;
    int* pHeight = &height;
    printf("int height = 10;\n");
    printf("height: %d\n", height);
    printf("pHeight: %d\n", *pHeight);
    *pHeight = 15;
    printf("*pHeight = 15;\n");
    printf("height: %d\n", height);
    printf("pHeight: %d\n", *pHeight);

}
