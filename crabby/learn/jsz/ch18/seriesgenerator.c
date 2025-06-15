#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "seriesgenerator.h"

static int seriesNumber = 101;

int seedWithDefaultRange(void)
{
    int seed = time(NULL);
    srand(seed);

    int lb = 100000;
    int ub = 999999;
    return (rand() % (ub - lb + 1) + lb);
}

int seedWithCustomRange(int lBound, int uBound)
{
    int seed = time(NULL);
    srand(seed);

    int lb = lBound;
    int ub = uBound;
    return (rand() % (ub - lb + 1) + lb);
}

void seriesStart(int seed)
{
    seriesNumber = seed;
}

int series(void)
{
    return seriesNumber++;
}
