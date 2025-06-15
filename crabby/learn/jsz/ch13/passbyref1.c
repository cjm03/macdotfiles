#include <stdio.h>

double RectPerimeter(double* pH, double *pW)
{
    *pH += 10.0;
    *pW += 10.0;
    return 2 * (*pW + *pH);
}

int main(void)
{
    double height = 15.0;
    double width = 22.5;
    printf("before: %lf | %lf\n", height, width);
    double* pHeight = &height;
    double* pWidth = &width;
    double perimeter = RectPerimeter(pHeight, pWidth);
    printf("\nafter: %lf | %lf\n", height, width);
    printf("%#lx    %lf\n", (unsigned long)pHeight, *pHeight);
    printf("%#lx    %lf\n", (unsigned long)pWidth, *pWidth);
    
}


