/**
 * Author: David Slay
 * Summary: Rule ARR36-C and rule EXP46-C example working code
 */
#include <stdio.h>
#include <stdbool.h>

#define MY_ARR_SIZE 5

int main(void)
{
    int arr[MY_ARR_SIZE];
    int *curArrPtr = arr;
    /*
    Rule ARR36-C: Do not subtract or compare two pointers that do not refer to the same array
    Done by subtracting pointers that point to the same array, as we subtract a pointer at one element past the array
    from a pointer at the beginning of the array.
     */
    int freeElements = (&(arr[MY_ARR_SIZE]) - curArrPtr);

    printf("Input number to add to the array: ");

    int inputNum = 0;
    int readErr = scanf("%d", &inputNum);

    /*
    Rule EXP46-C: Do not use a bitwise operator with a Boolean-like operand
    This code uses the && operator rather than using the bitwise & operator to do boolean logic.
    */
    while (readErr > 0 && freeElements > 0)
    {
        *curArrPtr = inputNum;
        curArrPtr++; // increment pointer

        // subtract pointers that point to the same array
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
