/**
 * Author: Waleed
 * Summary: ere, the addition of `a` and `b` is performed using `unsigned long long` to prevent overflow. The program checks if the result exceeds the maximum value of `unsigned int` before safely casting it back, ensuring accurate computation and preventing data loss.
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned int a = UINT_MAX;
    unsigned int b = 1;
    unsigned long long result;

    // Perform arithmetic in a larger size to prevent overflow
    result = (unsigned long long)a + b;

    if (result > UINT_MAX)
    {
        printf("Overflow detected: result = %llu\n", result);
    }
    else
    {
        unsigned int safe_result = (unsigned int)result;
        printf("Safe result: %u\n", safe_result);
    }

    return 0;
}