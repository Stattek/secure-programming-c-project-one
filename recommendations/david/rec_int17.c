/**
 * Author: David Slay
 * Summary: Rule INT17-C example working code
 */
#include <stdio.h>

int main(void)
{
    // create mask with all bits set to 1
    const unsigned long long int MASK = -1;
    printf("The mask: %llu\n", MASK);

    unsigned long long int myVal = __LONG_LONG_MAX__ >> 2;
    printf("The original value: %llu\n", myVal);

    unsigned long long int result = MASK ^ myVal;
    printf("Result of XOR: %llu\n", result);
    return 0;
}