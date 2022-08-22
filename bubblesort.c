#include "bubblesort.h"
#include <stdio.h>
#include "macros.h"

// Para trocar
void swap(char *, char *)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble Sort
void bubbleSort(rawData *, int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (rawData[j] > rawData[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
