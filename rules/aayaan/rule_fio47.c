
/**
 * @file rule_fio47.c
 * @author Aayaan Shaikh
 * @brief demonstrates using correct format string
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>

int main(void)
{
    double sTime = 5.9876;
    char procNo = 'x';

    // FIO47-C: Use valid format strings
    // avoided using %f (wong rounding) or %d (int data type)
    // used format string %.2f(hundreths place)

    printf("Process %c took(to the hundreths place): %.2f seconds. \n", procNo, sTime);

    return 0;
}