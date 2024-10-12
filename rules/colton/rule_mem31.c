/**
 * Author: Colton Longstreth
 * Summary: Rule MEM31-C example working code
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // creates int array on heap
    int *int_pointer = (int *)malloc(5 * sizeof(int));
    int product = 0;
    // takes user input to get multiplied
    for (int i = 0; i < 5; i++)
    {
        printf("Enter digit to get multiplied: ");
        scanf("%d", &int_pointer[i]);
    }

    product = int_pointer[0] * int_pointer[1] * int_pointer[2] * int_pointer[3] * int_pointer[4];

    printf("Product is: %d", product);
    // frees array memory
    free(int_pointer);
    return 0;
}
