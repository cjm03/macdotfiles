#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/* ctype.h functions for simple tests on given character c
   these return 0 if FALSE and non-zero if TRUE
    int  isalnum(int c);     // alphabets or numbers
    int  isalpha(int c);     // alphabet only
    int  isascii(int c);     // in range of 0..127
    int  iscntrl(int c);     // in range 0..31 or 127
    int  isdigit(int c);     // number ('0'..'9')
    int  islower(int c);     // lower case alphabet
    int  isnumber(int c);    // number ('0'..'9')
    int  isprint(int c);     // printable character
    int  ispunct(int c);     // punctuation
    int  isspace(int c);     // space
    int  isupper(int c);     // upper case alphabet

   ctype.h functions for altering a given character
    int digittoint(int c);  // convert char to its number value
    int tolower(int c);     // convert to lower case
    int toupper(int c);     // convert to upper case 
*/
bool isDigit(int c)
{
    bool bDigit = false;
    if (c >= '0' && c <= '9')
        bDigit = true;
    return bDigit;
}

bool isWhitespace(int c)
{
    bool bSpace = false;
    switch (c) {
        case ' ':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r': bSpace = true; break;
        default: bSpace = false; break;
    }
    return bSpace;
}

int toLower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }
    return c;
}

int digitToInt(int c)
{
    int i = c;
    if (c >= '0' && c <= '9') {
        i = c - '0';
    }
    return i;
}

int main()
{
    char aChar = '\\';
    char aLower = 'F';
    char aDigit = '3';
    if (isWhitespace(aChar)) {
        printf("%c is whitespace\n", aChar);
    } else {
        printf("%c is not whitespace\n", aChar);
    }
    if (isDigit(aChar)) {
        printf("%c is a digit\n", aChar);
    } else {
        printf("%c is not a digit\n", aChar);
    }
    printf("%c to lowercase: %c\n", aLower, toLower(aLower));
    printf("%c to digit: %d\n", aDigit, digitToInt(aDigit));
}
