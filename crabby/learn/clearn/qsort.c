#include <stdio.h>


void qsortLocal(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsortLocal(v, left, last - 1);
    qsortLocal(v, last + 1, right);
    for (int j = 0; j < 10; j++) {
        printf("%d ", v[j]);
    }
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    int arrayLocal[10];
    int arrayL = 6;
    int arrayR = 5;
    arrayLocal[0] = arrayL;
    for (int i = 1; i < 9; i++) {
        arrayLocal[i] = 13 - i;
    }
    arrayLocal[9] = arrayR;
    qsortLocal(arrayLocal, arrayL, arrayR);
}
