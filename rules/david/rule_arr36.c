/**
 * Author: David Slay
 * Summary: Rule ARR36-C example working code
 */
#include <stdio.h>
#include <stdbool.h>

#define MY_ARR_SIZE 5

int main()
{
    int arr[MY_ARR_SIZE];
    int *curArrPtr = arr;
    int freeElements = (&(arr[MY_ARR_SIZE]) - curArrPtr);

    printf("Input number to add to the array: ");

    int inputNum = 0;
    int readErr = scanf("%d", &inputNum);
    while (readErr > 0 && freeElements > 0)
    {
        *curArrPtr = inputNum;
        curArrPtr++; // increment pointer
        freeElements = (&(arr[MY_ARR_SIZE]) - curArrPtr);

        if (freeElements > 0)
        {
            printf("Input number to add to the array: ");
            readErr = scanf("%d", &inputNum);
        }
    }

    // handle error
    if (readErr <= 0)
    {
        fprintf(stderr, "Could not read user input\n");
        return 1;
    }

    // print out the array at the end
    printf("The array:\n");
    for (int i = 0; i < MY_ARR_SIZE - freeElements; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); // new line

    return 0;
}
