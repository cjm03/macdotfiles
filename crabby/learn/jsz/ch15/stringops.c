#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string1[] = "hello";
    char string2[] = "friend";
    char* string3 = "amigo";
    char string4[100] = "Hello my rly good friend, ";
    int lStr1 = strlen(string1);
    int lStr2 = strlen(string2);
    int lStr3 = strlen(string3);
    printf("str1: %d , str2: %d , str3: %d\n", lStr1, lStr2, lStr3);
    strcat(string4, string1);
    printf("%s\n", string4);
    strcat(string4, string3);
    printf("%s\n", string4);
}
/*      IT IS IMPERATIVE TO PROVIDE NULL-TERMINATED STRINGS TO THESE FUNCTIONS
strcat(char *, const char *)        Concatenates two strings. Appends a copy of one null-terminated
                                    string to the end of a target null-terminated string, then adds
                                    a terminating '\0' character. The target string must have 
                                    sufficient space to hold the result.

strcpy(char *, const char *)        Copies one string to another (including the terminating '\0' 
                                    character)

strtok(char *, const char *)        Breaks a string into tokens or sub-strings

strcmp(const char *, const char *)  Compares two strings. Lexicographically compares two 
                                    null-terminated strings

strchr(const char *, int)           Locates char in a string, finds first occurrence

strrchr(const char *, int)          Locates char in a string in reverse, finds last occurrence

strpbrk(const char *, const char *) Locates any set of characters in a string

strstr(const char *, const char *)  Locates a substring in a string
*/

/* Safer String Operations \\
Not always possible to ensure that a null-terminated array of characters is provided. This is 
especially common when reading from a file. To prevent mayhem, a few string functions have a
built-in limiter that only operates on the first N characters of the string array.

 - Copy and append strings:
    strncat()   Concatenates two strings. Appends a copy of up to N characters of one 
                null-terminated string to the end of a target null-terminated string, 
                then adds a terminating '\0' character. Target string must have enough space 
                to hold result.
    strncpy()   Copies up to N characters of one string to another. Depending on the size of the
                destination, the destination string may either be filled with the nul characters
                or may not be null-terminated
 - Compare strings:
    strncmp()   Compares two strings. Lexicographically, compares no more than N characters of
                two null-terminated strings.


*/
