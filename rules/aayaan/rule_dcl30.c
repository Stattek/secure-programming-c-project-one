/**
 * @file rule_dcl30.c
 * @author Aayaan Shaikh
 * @brief demonstrates setting correct storage duration
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>

const char *p; // static storage duration, whole program

/**
 * @brief Sets a global pointer to point to a static value.
 */
void setPtrToName(void)
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