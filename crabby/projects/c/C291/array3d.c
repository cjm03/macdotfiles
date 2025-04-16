#include <stdio.h>

#define X 5
#define Y 4
#define Z 3

void printThreeDimArr()
{
    int a, b, c;
    int array3D[Z][Y][X] = {
        {
            {111, 112, 113, 114, 115}, 
            {121, 122, 123, 124, 125}, 
            {131, 132, 133, 134, 135}, 
            {141, 142, 143, 144, 145}
        }, 
        {
            {211, 212, 213, 214, 215}, 
            {221, 222, 223, 224, 225}, 
            {231, 232, 233, 234, 235}, 
            {241, 242, 243, 244, 245}
        }, 
        {
            {311, 312, 313, 314, 315}, 
            {321, 322, 323, 324, 325}, 
            {331, 332, 333, 334, 335}, 
            {341, 342, 343, 344, 345}
        }
    };

    printf("-----------------------------------\n");

    for (c = 0; c < Z; c++) {
        for (b = 0; b < Y; b++) {
            for (a = 0; a < X; a++) {
                printf("| %d |", array3D[c][b][a]);
            }
            printf("\n");
        }
        printf("-----------------------------------\n");
    }

    printf("array3D[0][0][0]: %d\n", array3D[0][0][0]);
    printf("array3D[0][0][4]: %d\n", array3D[0][0][4]);
    printf("array3D[0][3][4]: %d\n", array3D[0][3][4]);
    printf("array3D[2][3][4]: %d\n", array3D[2][3][4]);


}

void printTwoDimArr()
{
    int a, b;
    int array2D[Y][X] = {
        {11, 12, 13, 14, 15}, 
        {21, 22, 23, 24, 25}, 
        {31, 32, 33, 34, 35}, 
        {41, 42, 43, 44, 45}
    };

    printf("------------------------------\n");

    for (b = 0; b < Y; b++) {
        for (a = 0; a < X; a++) {
            printf("| %d |", array2D[b][a]);
        }
        printf("\n");
    }
    printf("------------------------------\n");
}

int main()
{
    printThreeDimArr();
    printTwoDimArr();
    return 0;
}