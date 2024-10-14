/**
 * Author: Waleed
 * Summary: In C programming, every non-void function must return a value of the appropriate type. If control reaches the end of a non-void function without encountering a return statement, the behavior is undefined. This rule mandates that all possible execution paths in a non-void function must culminate with a return statement that provides a value.
 */
#include <stdio.h>

/**
 * @brief Computes the factorial of a non-negative number
 *
 * @param n The integer for which to compute the factorial
 * @return The factorial of n if n is non-negative otherwise -1 to indicate an error
 */
int compute_factorial(int n)
{
    if (n < 0)
    {
        fprintf(stderr, "Error: Negative input is invalid.\n");
        return -1; // Indicate an error
    }
    else if (n == 0 || n == 1)
    {
        return 1; // Base case
    }
    else
    {
        return n * compute_factorial(n - 1); // Recursive call
    }
    // No paths leave the function without a return statement
}

int main(void)
{
    int number = 5;
    int result = compute_factorial(number);

    if (result != -1)
    {
        printf("Factorial of %d is %d\n", number, result);
    }
    else
    {
        printf("Failed to compute factorial of %d\n", number);
    }

    return 0;
}
