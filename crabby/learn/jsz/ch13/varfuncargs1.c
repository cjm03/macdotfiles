#include <stdio.h>

double rectPerimeter(double h, double w)
{
    h += 10.0;
    w += 10.0;
    return 2 * (w + h);
}

int main(void)
{
    double height = 15.0;
    double width = 22.5;
    double perimeter = rectPerimeter(height, width);
    printf("perimeter = %lf\n", perimeter);
}
