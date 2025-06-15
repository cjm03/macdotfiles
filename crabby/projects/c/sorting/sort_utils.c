#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort_utils.h"

                                                                                /*
-----helpers----------------------------------------------------------------------------------------
                                                                                */

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarr(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int* randArr(int* outSize)
{
    int size = rand() % 251 + 500;           // size is a random number between 100 and 150
    int* arr = malloc(size * sizeof(int));  // allocate memory (size of an int * size bytes)
    if (arr == NULL) {                      // 
        fprintf(stderr, "Malloc failed\n"); // ERROR HANDLING
        exit(1);
    }
    for (int i = 0; i < size; i++) {        // while i < size
        arr[i] = rand() % 1999 + 1;          // element at index i assigned random number 1-999
    }
    *outSize = size;                        // Return size by dereferencing param pointer variable
    return arr;                             // return the array
}

                                                                                /*
-----basic sorters----------------------------------------------------------------------------------
                                                                                */    

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {            // while i is less than size-1
        for (int j = 0; j < size - i - 1; j++) {    // while j is less than size-i-1
            if (arr[j] > arr[j + 1]) {              // if array element at index j is greater than the next index element
                swap(arr, j, j + 1);                // swap the two elements
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {        // while i is less than size-1
        int pos = i;                            // starting position is i
        for (int j = i + 1; j < size; j++) {    // j is one index further than i, and while j is less than size
            if (arr[pos] > arr[j]) {            // if array element at index pos is greater than array element at index j (one further than pos)
                pos = j;                        // skip it, and new pos is j (i + 1)
            }
        }                               
        if (pos != i) {                         // if pos was moved and is no longer same as i
            swap(arr, i, pos);                  // set element at index pos to element at index i
        }
    }
}

void insertionSort(int arr[], int size)
{
    // Starting from the second element
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0, ..., i-1] that are greater than key
        // to one position to the right of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Move the key to its correct position
        arr[j + 1] = key;
    }
}

                                                                                /*
-----merge sorter----------------------------------------------------------------------------------
                                                                                */

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int leftArr[n1], rightArr[n2];
    
    // Copy data to temp arrays
    for (i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    // Merge temp arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // Same but for rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        // Calculate midpoint
        int mid = left + (right - left) / 2;
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

                                                                                /*
-----quick sort-----------------------------------------------------------------------------------
                                                                                */

int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap2(&arr[i], &arr[j]);
        }
    }
    swap2(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

                                                                                /*
-----count sort------------------------------------------------------------------------------------
                                                                                */

void countSort(int arr[], int size)
{
    int M = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > M) {
            M = arr[i];
        }
    }
    int* countArr = (int*)calloc(M + 1, sizeof(int));
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }
    for (int i = 1; i <= M; i++) {
        countArr[i] += countArr[i - 1];
    }
    int* outArr = (int*)malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        outArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = outArr[i];
    }
    free(countArr);
    free(outArr);
}
