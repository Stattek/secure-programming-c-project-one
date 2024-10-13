/**
 * @file rule_int30.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief INT30: ensure that unsigned int operations do not wrap
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/**
 * @brief compares two ints and determines if they are too big to perform multiplication on
 *
 * @param a first int to compare
 * @param b second int to compare
 */
void tooBig(unsigned int a, unsigned int b)
{
    unsigned int mult;
    if (UINT_MAX - a < b)
    {
        printf("your number is too big\n");
    }
    else
    {
        mult = a * b;
        printf("here is your number: %u\n", mult);
    }
}

int main(void)
{
    srand(time(0));

    unsigned int a = rand() % UINT_MAX * 1.5;
    unsigned int b = rand() % UINT_MAX * 1.5;
    tooBig(a, b);
    return 0;
}