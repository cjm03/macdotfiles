#include <stdio.h>


void init2DArray(int row, int col, int array[row][col]);
void init3DArray(int x, int y, int z, int array[z][y][x]);
int sum2DArray(int row, int col, int array[row][col]);
int sum3DArray(int z, int y, int x, int array[z][y][x]);
void print2DArray( int row , int col , int array[row][col] );
void print3DArray( int z , int y , int x , int array[z][y][x] );

int main()
{
    const int size1D = 5;
    const int size2D = 4;
    const int size3D = 3;

    int array2D[size2D][size1D];
    int array3D[size3D][size2D][size1D];

    int total = 0;
    init2DArray( size2D , size1D , array2D );
    print2DArray( size2D , size1D , array2D );
    total = sum2DArray( size2D , size1D , array2D );
    printf( "Total for array2D is %d\n\n" , total );
    init3DArray( size3D , size2D , size1D , array3D );
    print3DArray( size3D , size2D , size1D , array3D );
    total = sum3DArray( size3D , size2D , size1D , array3D );
    printf( "Total for array3D is %d\n\n" , total );
}

void init2DArray(int row, int col, int array[row][col])
{
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            array[j][i] = (10 * (j + 1)) + (i + 1);
        }
    }
}

void init3DArray(int x, int y, int z, int array[z][y][x])
{
    for (int k = 0; k < z; k++) {
        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                array[k][j][i] = (100 * (k + 1)) + (10 * (j + 1)) + (i + 1);
            }
        }
    }
}

int sum2DArray(int row, int col, int array[row][col])
{
    int sum = 0;
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            sum += array[j][i];
        }
    }
    return sum;
}

int sum3DArray(int z, int y, int x, int array[z][y][x])
{
    int sum = 0;
    for (int k = 0; k < z; k++) {
        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                sum += array[k][j][i];
            }
        }
    }
    return sum;
}

void print2DArray( int row , int col , int array[row][col] ) {
    for( int j = 0 ; j < row ; j++ ) { // j : 0..(row-1)
        for( int i = 0 ; i < col ; i++ ) { // i : 0..(col-1)
            printf("%4d" , array[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void print3DArray( int z , int y , int x , int array[z][y][x] ) {
    for( int k = 0 ; k < z ; k++ ) { // k : 0..(z-1)
        for( int j = 0 ; j < y ; j++ ) { // j : 0..(y-1)
            for( int i = 0 ; i < x ; i++ ) { // i : 0..(x-1)
                printf("%4d" , array[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
