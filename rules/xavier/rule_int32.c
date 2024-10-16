/**
 * @file rule_int32.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief INT32: ensure that operations on signed integers do not result in overflow
 * @version 1.0
 * @date 2024-10-12
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/**
 * @brief Compares two ints and determines if they are too big to perform multiplication on
 *
 * @param a first int to compare
 * @param b second int to compare
 */
void tooMuch(int a, int b)
{
    if ((a > 0 && b > 0 && a > INT_MAX / b) || (a < 0 && b < 0 && a < INT_MAX / b) ||
        (a > 0 && b < 0 && b < INT_MIN / a) || (a < 0 && b > 0 && a < INT_MIN / b))
    {
        printf("Your number is too big\n");
    }
    else
    {
        int mult = a * b;
        printf("Here is your number: %d\n", mult);
    }
}

int main(void)
{
    srand(time(0));

    int a = rand() % (INT_MAX + 1);
    int b = rand() % (INT_MAX + 1);

    if (rand() % 2)
    {
        a = -a;
    }
    if (rand() % 2)
    {
        b = -b;
    }

    tooMuch(a, b);
    return 0;
}
