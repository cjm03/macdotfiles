#include <stdio.h>

/*
*   Syntax:
*       enum name {enumeration1, enumeration2, ... enumerationN};
*/

/*
    enum suit {spade, heart, diamond, club};
OR
    enum suit {
        spade,
        heart,
        diamond,
        club
    };
*/
// Compiler automatically assigns values to each enumerated item, so we could, but do not have to assign values.
/*                binary value assignment                   integer equiv. assignment
enum textStyle {                                    enum textStyle {
    lowercase       = 0x00000001,                       lowercase       = 1,
    bold            = 0x00000010,                       bold            = 2,
    italic          = 0x00000100,                       italic          = 4,
    underline       = 0x00001000,                       underline       = 8,
    strikethrough   = 0x00010000                        strikethrough   = 16
};                                                  };
*/
enum textStyle {
    lowercase       = 1,    // 0x00000001
    bold            = 2,    // 0x00000010
    italic          = 4,    // 0x00000100
    underline       = 8,    // 0x00001000
    strikethrough   = 16    // 0x00010000
};
int main()
{
    int style = bold | italic;  // 0x00000110
    int otherStyle = italic + underline;
    if (style & bold) {         // 0x00000110 & 0x00000010 = 0x00000010
        printf("bold is on\n");
    } else {
        printf("bold is off\n");
    }
    if (style & underline) {
        printf("underline is on\n");
    } else {
        printf("underline is off\n");
    }
    if (style & italic) {
        printf("italic is on\n");
    } else {
        printf("italic is off\n");
    }
}
















