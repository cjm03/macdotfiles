#include <stdio.h>

typedef struct _RectDimensions {
    double height;
    double width;
    double perimeter;
} RectDimensions;

void calculateRectPerimeter(RectDimensions* pRD)
{
    pRD->height += 10.0;
    pRD->width += 10.0;
    pRD->perimeter = 2 * (pRD->height * pRD->width);
}

int main(void)
{
    RectDimensions rd;
    rd.height = 15.0;
    rd.width = 22.5;
    calculateRectPerimeter(&rd);
    printf("height: %lf | width: %lf | perimeter: %lf\n",
           rd.height, rd.width, rd.perimeter);
}
