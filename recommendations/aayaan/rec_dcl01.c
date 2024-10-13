/**
 * @file rec_dcl01.c
 * @author Aayaan Shaikh
 * @brief demonstrates proper naming of variables in subscopes
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>

int main(void)
{

    int numbers[10];

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i;
    }

    printf("Numbers from 1 to 10 and their squares:\n");
    for (int i = 0; i < 10; i++)
    {
        // DCL01-C: Do not reuse variable names in subscopes
        // avoided using another variable named i since it was already defined in larger scope
        // used variable name j instead
        int j = (i * i);

        printf("%d squared: %d, \n", numbers[i], j);
    }

    return 0;
}