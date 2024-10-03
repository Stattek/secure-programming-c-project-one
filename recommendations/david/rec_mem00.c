/**
 * Author: David Slay
 * Summary: Rule MEM00-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NUM_ARRAY_ELEMENTS 5

// TODO: doc
void printIntArray(int *arr, int arrLen)
{
    printf("[");
    for (int i = 0; i < arrLen; i++)
    {
        printf("%d", arr[i]);

        if (i < arrLen - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

// TODO: doc
void fillRandIntArray(int *arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        // set array values to random values between 0-100
        arr[i] = rand() % 101;
    }
}

int main(void)
{
    // seed random number generator
    srand(time(NULL));

    // create array on the heap
    int *arr = malloc(NUM_ARRAY_ELEMENTS * sizeof(int));
    if (!arr)
    {
        fprintf(stderr, "Error allocating array\n");
        return 1;
    }

    fillRandIntArray(arr, NUM_ARRAY_ELEMENTS);

    printf("Random contents of arr:\n");
    printIntArray(arr, NUM_ARRAY_ELEMENTS);

    // free on the same level of abstraction
    free(arr);
    return 0;
}