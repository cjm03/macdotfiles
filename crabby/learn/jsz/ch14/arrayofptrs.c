#include <stdio.h>

int main(void)
{
    int arrayStd[3][5] = {{11, 12, 13, 14, 15},
                          {21, 22, 23, 24, 25},
                          {31, 32, 33, 34, 35}};
    // Array of pointers.
    int* arrayPtr[3] = {NULL};
    // Array sizes and pointer for pointer traversal.
    const int rows = 3;
    const int cols = 5;
    int* pInteger;
    // Sub-arrays.
    int array1[5]   = {11, 12, 13, 14, 15};
    int array2[5]   = {21, 22, 23, 24, 25};
    int array3[5]   = {31, 32, 33, 34, 35};
    arrayPtr[0] = array1;
    arrayPtr[1] = array2;
    arrayPtr[2] = array3;
    // Do traversals.
    printf("Print both arrays using array notation, array[i][j].\n\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %2d ", arrayStd[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %2d ", arrayPtr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Print both arrays using pointers, *pInteger++.\n\n");

    pInteger = &(arrayStd[0][0]);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %2d ", *pInteger++);
        }
        printf("\n");
    }
    printf("\n");

    // Experiment:
    pInteger = arrayPtr[0];
    for (int i = 0; i < rows; i++) {
        pInteger = arrayPtr[i];
        for (int j = 0; j < cols; j++) {
            printf(" %2d ", *pInteger++);
        }
        printf("\n");
    }
    printf("\n");
}
