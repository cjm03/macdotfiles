#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seriesgenerator.h"

int main()
{
    int current = seedWithDefaultRange();
    printf("%d is current seeded start point\n", current);
    for (int i = 0; i < 5; i++) {
        printf("incrementing.. %d\n", series());
    }
    return 0;
}
