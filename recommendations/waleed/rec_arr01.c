/**
 * Author: Waleed
 * Summary: In this example, `sizeof(array)` gives the total size of the array in bytes, 
 * and dividing it by `sizeof(array[0])` calculates the number of elements. 
 * The `print_array` function receives the array pointer and its size, 
 * avoiding the misuse of `sizeof` on a pointer.
 */
#include <stdio.h>

void print_array(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(array) / sizeof(array[0]); // Correctly calculates number of elements

    print_array(array, array_size);

    return 0;
}
