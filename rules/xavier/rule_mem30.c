/**
 * @file rule_mem30.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief MEM30: don't access freed memory
 * @version 0.1
 * @date 2024-10-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int));
    int *ptr_two = (int *)malloc(sizeof(int));

    if (ptr == NULL || ptr_two == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }  

    // give a value to ptr and access it
    // all good
    *ptr = 7;
    printf("Value before freeing memory: %d\n", *ptr);

    // free the ptr and access it
    // not all good, results in garbage being spit out (undefined behavior)
    free(ptr);
    printf("Attempting to access freed memory: %d\n", *ptr);

    // give a value to ptr_two and access it
    // all good
    *ptr_two == 25;
    printf("Value before freeing memory: %d\n", *ptr_two);

    // freeing ptr_two and then assiging a null value to it
    // this is what u should do
    free(ptr_two);
    ptr_two = NULL;

    if (ptr_two == NULL)
    {
        printf("ptr_two has been freed and set to NULL");
    }
    else
    {
        printf("ptr_two has NOT been freed and set to NULL properly");
    }

    return 0;
}