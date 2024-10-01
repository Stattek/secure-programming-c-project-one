/**
 * Author: David Slay
 * Summary: Rule FLP32-C example working code
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Safely does asin(), checking to see if it can be done.
 *
 * @param num The number to do the asin() on.
 * @param resultOut The output result.
 *
 * @returns true on error, false on success.
 */
bool safe_asin(double num, double *resultOut)
{
    if (!resultOut || !isgreaterequal(num, -1.0) || !islessequal(num, 1.0))
    {
        // outside of desired range of (-1 <= x <= 1) or resultOut is NULL
        return true;
    }

    // safely do this math now
    *resultOut = asin(num);
    return false;
}

int main(void)
{
    double result = 0;
    double num = 0;

    printf("Input number to perform asin on: ");

    if (scanf("%lf", &num) <= 0)
    {
        fprintf(stderr, "Could not read user input\n");
        return 1;
    }

    if (safe_asin(num, &result))
    {
        fprintf(stderr, "Could not perform safe_asin (num: %lf result: %lf)\n", num, result);
        return 1;
    }

    printf("Result: %lf\n", result);

    return 0;
}
