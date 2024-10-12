/**
 * @file ARR39-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates printing array using pointer to iterate
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>

enum
{
    SIZE = 5
};

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // ARR39-C: Do not add or subtract a scaled integer to a pointer
    // avoided compare with arr + sizeof(arr) (Incorrect size)
    // compare with arr + SIZE instead to loop for each element
    while (ptr < (arr + SIZE))
    {
        printf("%d ", *ptr);
        ptr++;
    }
    return 0;
}