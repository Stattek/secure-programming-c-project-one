/**
 * @file DCL30-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates setting correct storage duration
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

const char *p; // static storage duration, whole program

void setPtrToName()
{
    // DCL30-C: Declare objects with appropriate storage durations
    // avoided setting wrong storage duration automatic for char name
    // compare with arr + SIZE instead to loop for each element
    static const char name = 'X'; // static storage duration, whole program
    p = &name;
}

int main(void)
{
    setPtrToName();

    printf("Name: %c\n", *p);

    return 0;
}