#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <stdio.h>

// #define ARR_MAX 2048
#define ARR_MAX 12

void swap(int* arr, int i, int j);
void swap2(int* a, int* b);
void printarr(int* arr, int size);
int* randArr(int* outSize);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void countSort(int arr[], int size);

#endif
