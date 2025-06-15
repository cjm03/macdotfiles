/* seriesgenerator.h */
#include <stdio.h>
#include <stdlib.h>

int seedWithDefaultRange(void);
int seedWithCustomRange(int lBound, int uBound);
void seriesStart(int seed);
int series(void);
