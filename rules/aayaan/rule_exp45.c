/**
 * @file rule_exp45.c
 * @author Aayaan Shaikh
 * @brief demonstrates proper comparison in selection statement
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>

int main(void)
{
    int a = 5, b = 10;

    // EXP45-C: Do not perform assignments in selection statements
    // avoided using if(a=b) which would assert equality
    // compare with (a==b) for correct comparison
    if (a == b)
    {
        printf("a is equal to b\n");
    }
    else
    {
        printf("a is not equal to b\n");
    }

    return 0;
}