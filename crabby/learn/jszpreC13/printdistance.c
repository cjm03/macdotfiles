#include <stdio.h>

void printDistance( double );

int main( void )
{
    double feet = 5280.0;
    printDistance( feet );
    printf( "feet = %12.3g\n" , feet );
    return 0;
}

// Given feet, print the distance in feet and yards.
/*
void printDistance( double f )
{
    printf( "The distance in feet is %12.3g\n" , f );
    f = f / 3.0 ;
    printf( "The distance in yards is %12.3g\n" , f );
}
*/

// A better version
void printDistance(double feet)
{
    double yards = feet / 3.0;
    printf("The distance in feet is %12.3g\n", feet);
    printf("The distance in yards is %12.3g\n", yards);
}
