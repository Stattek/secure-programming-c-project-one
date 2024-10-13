/**
 * Author: David Slay
 * Summary: Rule FLP32-C example working code
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Safely does acos(), checking to see if it can be done.
 *
 * @param num The number to do the acos() on.
 * @param resultOut The output result.
 *
 * @returns true on error, false on success.
 */
bool safe_acos(double num, double *resultOut)
{
    /*
    Rule FLP32-C: Prevent or detect domain and range errors in math functions
    Checks the domain that acos() can do to avoid domain errors.
    */
    if (!resultOut || !isgreaterequal(num, -1.0) || !islessequal(num, 1.0))
    {
        // outside of desired domain of (-1 <= x <= 1) or resultOut is NULL
        return true;
    }

    // safely do this math now
    *resultOut = acos(num);
    return false;
}

int main(void)
{
    double result = 0;
    double num = 0;

    printf("Input number to perform acos on: ");

    if (scanf("%lf", &num) <= 0)
    {
        fprintf(stderr, "Could not read user input\n");
        return 1;
    }

    if (safe_acos(num, &result))
    {
        fprintf(stderr, "Could not perform safe_acos (num: %lf result: %lf)\n", num, result);
        return 1;
    }

    printf("Result: %lf\n", result);

    return 0;
}
