/**
 * @file rule_arr39.c
 * @author Aayaan Shaikh
 * @brief demonstrates printing array using pointer to iterate
 * @version 0.1
 * @date 2024-10-12
 *
 */

#include <stdio.h>

enum
{
    SIZE = 5
};

int main(void)
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
    printf("\n");
    return 0;
}