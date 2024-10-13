/**
 * @file rule_exp34.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief EXP34: do not dereference null pointers
 * @version 1.0
 * @date 2024-10-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // creating a null ptr
    int *ptr = NULL;

    // below is attempting to dereference a null ptr, very not good and can lead to undefined behavior
    // commented bc i dont want my code to explode
    // *ptr = 10;

    // below is checking if ptr is null before attempting to dereference
    if (ptr == NULL)
    {
        printf("don't dereference a null ptr!");
        return 1;
    }
    else
    {
        printf("thank u for following the rules :)");
        return 0;
    }
}