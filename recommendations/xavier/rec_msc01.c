/**
 * @file rec_msc01.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief MSC01: Strive for logical completeness
 * @version 1.0
 * @date 2024-10-12
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief not checking what happens when num1 and num3 are equal
 *
 * @param num1 first int input
 * @param num2 second int input
 * @param num3 third int input
 */
void wrongFunction(int num1, int num2, int num3)
{
    if (num1 == num2)
    {
        printf("num1 and num2 equal\n");
    }
    else if (num2 == num3)
    {
        printf("num2 and num3 equal\n");
    }
    printf("No numbers are equal\n");
}

/**
 * @brief comparing all numbers, fully satisfying logic
 *
 * @param num1 first int input
 * @param num2 second int input
 * @param num3 third int input
 */
void rightFunction(int num1, int num2, int num3)
{
    if (num1 == num2)
    {
        printf("num1 and num2 equal\n");
    }
    else if (num2 == num3)
    {
        printf("num2 and num3 equal\n");
    }
    else if (num1 == num3)
    {
        printf("num1 and num3 equal\n");
    }
    else
    {
        printf("No numbers are equal\n");
    }
}

int main(void)
{
    int a = 3;
    int b = 2;
    int c = 3;

    wrongFunction(a, b, c);
    rightFunction(a, b, c);

    return 0;
}