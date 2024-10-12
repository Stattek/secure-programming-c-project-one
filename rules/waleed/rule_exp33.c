/**
 * Author: Waleed
 * Summary: By initializing the array, we ensure that all elements have a known value before being read.
 */
#include <stdio.h>

int main(void)
{
    int numbers[5] = {0}; // Initialize all elements to zero

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}