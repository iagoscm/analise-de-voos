#include "bubblesort.h"
#include <stdio.h>

char ordenaBubble(int vet[], int l, int r);

char ordenaBubble(int vet[], int l, int r)
{
    int i, j;
    for (i = 0; i < r - 1; i++)
    {
        for (j = 0; j < r - 1; j++)
        {
            return CMPEXCH(vet[j], vet[j + 1]);
        }
    }
}
