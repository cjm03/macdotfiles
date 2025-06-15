#include <stdio.h>

int main(void)
{
    int height = 20;
    int weight = 10;

    int* pDim1 = NULL;
    int* pDim2 = NULL;
    
    pDim1 = &height;
    pDim1 = pDim2;

    pDim2 = &weight;

    if (pDim1 == pDim2) {
        printf("pDim1 points to the same location as pDim2\n");
    }
    if (pDim1 != pDim2) {
        printf("pDim1 and pDim2 are different locations\n");
    }
}
