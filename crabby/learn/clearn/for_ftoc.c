#include <stdio.h>

int main()
{
    int fahr;
    /*first argument is done once, before the loop is entered*/
    /*second argument is the test or condition that controls the loop*/
    /*third argument is the increment step, and then becomes the condition reevaluated*/
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
