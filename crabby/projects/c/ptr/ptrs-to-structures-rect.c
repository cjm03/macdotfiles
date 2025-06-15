#include <stdio.h>

typedef struct _RectDimensions {
    double h;
    double w;
    double p;
} RectDimensions;

void CalculateRectPerimeter(RectDimensions* pRD)
{
    pRD->h += 10.0;
    pRD->w += 10.0;
    pRD->p = 2 * (pRD->h * pRD->w);
}

int main(void)
{
    RectDimensions rd;          // Declare struct rd as a RectDimensions structure 
    rd.h = 15.0;                // Assign rd's height to 15.0
    rd.w = 22.5;                // Assign rd's width to 22.5
    printf("Local: \n\trd.h = %lf\trd.w = %lf\n", rd.h, rd.w);
    CalculateRectPerimeter(&rd);
    printf("After calling CalculateRectPerimeter: \n\trd.h = %lf\trd.w = %lf\n", rd.h, rd.w);
}

