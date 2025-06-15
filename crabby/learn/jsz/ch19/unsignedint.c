#include <stdio.h>

int main(void)
{
    int smallInt = 12;
    int largeInt = (1024*1024*3) + (1024*2) + 512 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    int negativeInt = -smallInt;
    unsigned anUnsigned = 130;

    printf("Unsigned Printf\n");
    printf(" Base Base-8 Base-10 Base-16 BASE-16\n");
    printf(" Name octal unsigned hexadecimal HEXADECIMAL\n");
    printf(" Specifier %%12o %%12u %%12x %%12X\n");
    printf(" [%12o] [%12u] [%12x] [%12X]\n", smallInt, smallInt, smallInt, smallInt);
    printf(" [%#12o] [%12u] [%#12x] [%#12X]\n", smallInt, smallInt, smallInt, smallInt);
    printf(" [%12o] [%12u] [%12x] [%12X]\n\n", largeInt, largeInt, largeInt, largeInt);
    printf(" [%#12o] [%12u] [%#12x] [%#12X]\n\n", largeInt, largeInt, largeInt, largeInt);
    printf(" [%12o] [%12u] [%12x] [%12X]\n\n", anUnsigned, anUnsigned, anUnsigned, anUnsigned);
    printf(" [%#12o] [%12u] [%#12x] [%#12X]\n\n", anUnsigned, anUnsigned, anUnsigned, anUnsigned);
}
