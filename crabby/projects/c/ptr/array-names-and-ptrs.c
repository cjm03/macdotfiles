#include <stdio.h>

int main(void)
{
    const int arraySize = 5;
    int array[5] = {1, 2, 3, 4, 5};
    int* pArray1 = NULL;
    int* pArray2 = NULL;

    pArray1 = array;        // the value of pArray1 is now the address of the zeroth element of array[]

    pArray2 = &array[0];    // the value of pArray2 is now also the address of the zeroth element of array[]
                            // this is just a more explicit way of assignment
    
    // Accessing the elements of array using array notation---[ and ]:
    array[0] = 1;   // first element (zeroth offset)
    array[1] = 2;                                                           //    E
    array[2] = 3;                                                           //    Q
    array[3] = 4;                                                           //    U
    array[4] = 5;   // fifth element (fourth offset)                        //    I
                                                                            //    V 
    // Accessing array elements via pointers, using pointer arithmetic:     //    A
    *(pArray1 + 0) = 1;     // first element (zeroth offset)                //    L
    *(pArray1 + 1) = 2;     // second element (first offset)                //    E
    *(pArray1 + 2) = 3;     // third element (second offset)                //    N
    *(pArray1 + 3) = 4;     // fourth element (third offset)                //    T
    *(pArray1 + 4) = 5;     // fifth element (fourth offset)
}


