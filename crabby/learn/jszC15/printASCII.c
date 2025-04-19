/*  Prints the second group of ASCII characters in the range of 32 to 63 (punctuation & digits)
*/
#include <stdio.h>

int main(void)
{
    char c1, c2, c3, c4;
    printf("| Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex |\n");
    printf("|-------------|-------------|-------------|\n");
    for (int i = 0; i < 32; i++) {
        c1 = i;
        c2 = i + 32;
        c3 = i + 64;
        c4 = i + 96;

        if (c4 == 127) {
            printf("| %c %3d  %#x | %c %3d  %#x |%s %3d %#x |",
                   c2, c2, c2,
                   c3, c3, c3,
                   "DEL", c4, c4);
        } else {

        // printf statement does three things:
        // first it prints c2 as a character with %c 
        // second it prints c2 as a decimal value with %d
        // third it prints c2 as a hex value with %x
                // the '#' in %#x prepends the hex number with 0x
            printf("| %c %3d  %#x | %c %3d  %#x | %c %3d  %#x |",
                   c2, c2, c2,
                   c3, c3, c3,
                   c4, c4, c4);
            printf("\n");
        }
    }
}
