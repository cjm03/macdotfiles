#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char string0[8] = {0};
    char string1[8] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char string2[8] = "hello";
    char string3[] = "hello";
    char* string4 = "hello";
    printf("A) 0:\"%s\" 1:\"%s\" 2:\"%s\" 3:\"%s\" 4:\"%s\"\n\n",
           string0, string1, string2, string3, string4);
    string0[0] = 'H';
    string1[0] = 'H';
    string2[0] = toupper(string2[0]);
    string3[0] = toupper(string3[0]);
    // string4[0] = 'H';  // cant do this because its a pointer to a string literal (constant)
    char* string5 = "Hello"; // assign pointer to new string
    printf("B) 0:\"%s\"  1:\"%s\"  2:\"%s\"  3:\"%s\"  4:\"%s\"\n\n",
           string0, string1, string2, string3, string5);
}
