#include <stdio.h>

double RectPerimeter(double* pH, double* pW)    // take in two pointer variables
{
    *pH += 10.0;    // dereference the first pointer variable to modify its target's value (the value at the address in 
                    // which the pointer points to)
    *pW += 10.0;    // dereference the second pointer variable to also modify its target's value
    return 2 * (*pW + *pH);     // return the result of the dereferenced pointer's values added together and * 2
}

int main(void)
{
    double height = 15.0;   // initialize variable height with 15.0
    double width = 22.5;    // initialize variable width with 22.5
    printf("Original height = %lf\tOriginal width = %lf\n", height, width);
    double* pHeight = &height;  // initialize pointer variable pHeight with address of variable height
    double* pWidth = &width;    // initialize pointer variable pWidth with address of variable width
    double perimeter = RectPerimeter(pHeight, pWidth);  // pass both pointer variables to function RectPerimeter and
                                                        // assign the return value to variable perimeter
    printf("New height = %lf     \tNew width = %lf\n", height, width);
}

