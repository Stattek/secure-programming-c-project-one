/**
 * @file rule_mem35.c
 * @author Aayaan Shaikh
 * @brief demonstrates allocating sufficent memory for object
 * @version 0.1
 * @date 2024-10-12
 *
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Allocates an array on the heap and fills it.
 *
 * @param len The length of the array.
 */
void allocateIntArr(size_t len)
{
    int *arr;

    // MEM35-C: Allocate sufficient memory for an object
    // avoided allocating wrong size: sizeof(float)
    // compare with arr + SIZE instead to loop for each element
    arr = (int *)malloc(len * sizeof(int));

    // check for success
    if (arr == NULL)
    {
        perror("Error: failed to allocate memory");
        return;
    }

    // fill array
    for (size_t i = 0; i < len; i++)
    {
        arr[i] = (int)i;
    }

    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main(void)
{

    size_t len;

    printf("Enter the length of the array: ");
    scanf("%zu", &len);

    allocateIntArr(len);

    return 0;
}
