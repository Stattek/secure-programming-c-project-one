/**
 * @file rec_exp15.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief MSC01: Strive for logical completeness
 * @version 1.0
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void wrongFunction(int num1, int num2, int num3)
{
    if (num1 == num2)
    {
        printf("num1 and num2 equal");
    }
    else if (num2 == num3)
    {
        printf("num2 and num3 equal");
    }
    // we're not checking for what to do if num1 and num3 are equal
    printf("No numbers are equal\n");
}

void rightFunction(int num1, int num2, int num3)
{
    if (num1 == num2)
    {
        printf("num1 and num2 equal");
    }
    else if (num2 == num3)
    {
        printf("num2 and num3 equal");
    }
    else if (num1 == num3)
    {
        printf("num1 and num3 equal");
    }
    else
    {
        printf("No numbers are equal");
    }
}

int main()
{
    int a = 3;
    int b = 2;
    int c = 3;

    wrongFunction(a, b, c);
    rightFunction(a, b, c);

    return 0;
}