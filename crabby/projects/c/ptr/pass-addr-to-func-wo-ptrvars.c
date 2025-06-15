#include <stdio.h>

void showInfo(int height, int width, int length)    // self-explanatory, hopefully...
{
    printf("  sizeof(int)  = %2lu\n", sizeof(int));
    printf("  sizeof(int*) = %2lu\n", sizeof(int*));
    printf("  [height, width, length] = [%2d,%2d,%2d]\n\n", height, width, length);
}

void showVar(char* pId, int* pDim)  // take in a pointer to a char which is just a string used as an identifier, and
{                                   // a pointer to an int
    printf("  address of %s = %#lx, value at address = %2d\n", 
           pId,                 // print the literal string passed to the function 
           (unsigned long)pDim, // cast variable pDim to type unsigned long in order to print its hexadecimal address
           *pDim);              // dereference the pointer to print its value rather than just its address
}

int main(void)
{
    int height = 10;
    int width = 20;     // declare and assign height, width, and length
    int length = 40;
    printf("\nValues:\n\n");
    showInfo(height, width, length);    // print the size of an integer, an integer pointer, and h, w, and l values
    printf("\nUsing address of each named variables...\n\n");
    showVar("height", &height);     // display info about height by simply passing its address
    showVar("width", &width);       // display info about width by simply passing its address
    showVar("length", &length);     // display info about length by simply passing its address
    printf("\n");
}

