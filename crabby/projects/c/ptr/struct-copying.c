#include <stdio.h>

typedef struct _RectDimensions {
    double h;
    double w;
    double p;
} RectDimensions;

RectDimensions RectPerimeter(RectDimensions rd)     // RectPerimeter takes in a variable of structure type RectDimensions
{                                   // rd is copied into an identical variable 'rd' which is local to the function   
    rd.h += 10.0;                   // its height is copied (15.0), and then 10 is added to the copy
    rd.w += 10.0;                   // its width is copied (22.5), and then 10 is added to the copy
    rd.p = 2 * (rd.h * rd.w);       // its perimeter is copied (NULL), and it is assigned with the result of 
                                    // rd.h * rd.w * 2
    return rd;                      // the copy is returned
}
                            // THIS ESSENTIALLY TAKES AN INITIALIZED STRUCTURE, COPIES IT INTO THE FUNCTION, AND
                            // RETURNS THE MODIFIED COPY. 
int main(void)
{
    RectDimensions rd;          // Declare struct rd as a RectDimensions structure 
    rd.h = 15.0;                // Assign rd's height to 15.0
    rd.w = 22.5;                // Assign rd's width to 22.5
    rd.p = 675.0;
    printf("\trd.h = %lf\trd.w = %lf\trd.p = %lf\n", rd.h, rd.w, rd.p);
    rd = RectPerimeter(rd);     // Pass rd to function RectPerimeter, and reassign rd with the new values
                                // returned from the function
    printf("\trd.h = %lf\trd.w = %lf\trd.p = %lf\n\n", rd.h, rd.w, rd.p);
    // If we wanted to keep the initial structure unmodified, we would simply assign the return value of the function
    // to a new variable, as follows:
    RectDimensions rdOrig, rdModified;
    rdOrig.h = 15.0;
    rdOrig.w = 22.5;
    rdModified = RectPerimeter(rdOrig);
    printf("\trdOrig.h = %lf    \trdOrig.w = %lf    \trdOrig.p = %lf\n", rdOrig.h, rdOrig.w, rdOrig.p);
    printf("\trdModified.h = %lf\trdModified.w = %lf\trdModified.p = %lf\n", rdModified.h, rdModified.w, rdModified.p);
}

