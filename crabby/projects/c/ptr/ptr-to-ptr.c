#include <stdio.h>

void showInfo(int height, int width, int length, int** ppDim)   // takes in integers height, width, and length, and also 
{                                                               // takes in a pointer to a pointer to an integer
    printf("  sizeof(int)  = %2lu\n", sizeof(int));
    printf("  sizeof(int*) = %2lu\n", sizeof(int*));
    printf("  [height, width, length] = [%2d,%2d,%2d]\n\n", height, width, length);
    printf("  address of pDimension = %#lx\n", 
           (unsigned long)ppDim);       // cast ppDim to an unsigned long in order to print its hexadecimal address
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

    int* pDimension = NULL;         // declare a ptr to an integer pDimension, and assign to NULL
    int** ppDimension = &pDimension;// declare a ptr to a ptr to an integer ppDimension, and assign to address of pDimension
    char* pIdentifier = NULL;       // declare a ptr to a char pIdentifier, and assign to NULL

    printf("\nValues:\n\n");

    showInfo(height, width, length, ppDimension);    // print the size of an integer, an integer pointer, hwl values,
                                                     // and address of ptr to ptr ppDimension
    
    printf("\nUsing address of each named variables...\n\n");

    pIdentifier = "height";             // assign the string "height" to pIdentifier
    pDimension = &height;               // assign the address of variable height to pDimension
    showVar(pIdentifier, pDimension);   
    pIdentifier = "width";              // reassign the string "width" to pIdentifier
    pDimension = &width;                // reassign the address of variable width to pDimension
    showVar(pIdentifier, pDimension);
    pIdentifier = "length";             // reassign the string "length" to pIdentifier
    pDimension = &length;               // reassign the address of variable length to pDimension
    showVar(pIdentifier, pDimension);
    printf("\n");
}

