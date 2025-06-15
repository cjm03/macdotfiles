#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "sort_utils.h"
#include "sort_utils.c"

int main(void)
{
    srand(time(NULL));
    int size;
    int* arr = randArr(&size);
    printarr(arr, size);
    printf("\n\n");

    clock_t start1, start2, start3, start4, start5, start6;
    clock_t end1, end2, end3, end4, end5, end6;
    double dur1, dur2, dur3, dur4, dur5, dur6;

    start1 = clock();
    bubbleSort(arr, size);
    end1 = clock();
    dur1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    start2 = clock();
    selectionSort(arr, size);
    end2 = clock();
    dur2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    start3 = clock();
    insertionSort(arr, size);
    end3 = clock();
    dur3 = (double)(end3 - start3) / CLOCKS_PER_SEC;

    start4 = clock();
    mergeSort(arr, 0, size - 1);
    end4 = clock();
    dur4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

    start5 = clock();
    quickSort(arr, 0, size - 1);
    end5 = clock();
    dur5 = (double)(end5 - start5) / CLOCKS_PER_SEC;

    start6 = clock();
    countSort(arr, size);
    end6 = clock();
    dur6 = (double)(end6 - start6) / CLOCKS_PER_SEC;

    printf("Bubble: %lf\nSelection: %lf\nInsertion: %lf\nMerge: %lf\nQuick: %lf\nCount: %lf\n",
           dur1, dur2, dur3, dur4, dur5, dur6);



    /* Bubble Sort */
    // int* arr1 = randArr(&size);
    // printarr(arr1, size);
    // printf("\n\n size: %d\n\n", size);
    // clock_t start = clock();
    // bubbleSort(arr1, size);
    // clock_t end = clock();
    // double dur = (double)(end - start) / CLOCKS_PER_SEC;
    // printarr(arr1, size);
    // free(arr1);
    // printf("\nBubble Sort Time: %lf\n", dur);

    // printf("\n\n\n");

    /* Selection Sort */
    // int* arr2 = randArr(&size);
    // printarr(arr2, size);
    // printf("\n\n size: %d\n\n", size);
    // start = clock();
    // selectionSort(arr2, size);
    // end = clock();
    // dur = (double)(end - start) / CLOCKS_PER_SEC;
    // printarr(arr2, size);
    // free(arr2);
    // printf("\nSelection Sort Time: %lf\n", dur);

    // printf("\n\n\n");

    /* Insertion Sort */
    // int* arr3 = randArr(&size);
    // printarr(arr3, size);
    // printf("\n\n size: %d\n\n", size);
    // start = clock();
    // insertionSort(arr3, size);
    // end = clock();
    // dur = (double)(end - start) / CLOCKS_PER_SEC;
    // printarr(arr3, size);
    // free(arr3);
    // printf("\nInsertion Sort Time: %lf\n", dur);

    /* Merge Sort */
    // int* arr4 = randArr(&size);
    // printarr(arr4, size);
    // printf("\n\n size: %d\n\n", size);
    // clock_t start = clock();
    // mergeSort(arr4, 0, size - 1);
    // clock_t end = clock();
    // double dur = (double)(end - start) / CLOCKS_PER_SEC;
    // printarr(arr4, size);
    // free(arr4);
    // printf("\nInsertion Sort Time: %lf\n", dur);

    /* Quick Sort */
    // int* arr5 = randArr(&size);
    // printarr(arr5, size);
    // printf("\n\n size: %d\n\n", size);
    // clock_t start = clock();
    // quickSort(arr5, 0, size - 1);
    // clock_t end = clock();
    // double dur = (double)(end - start) / CLOCKS_PER_SEC;
    // printarr(arr5, size);
    // free(arr5);
    // printf("\nInsertion Sort Time: %lf\n", dur);

    return 0;
}
