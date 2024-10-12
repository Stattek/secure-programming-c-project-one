/**
 * Author: David Slay
 * Summary: Recommendation INT17-C example working code
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    /*
    Recommendation INT17-C: Define integer constants in an implementation-independent manner
    Create mask with all bits set to 1 by setting to -1, which will set all bits to 1 on different implementations.
    */
    const unsigned int MASK = -1;
    printf("The mask: %u\n", MASK);

    // bitshift 2 to the right to have all bits except the first two set to 1
    unsigned int myVal = UINT_MAX >> 2;
    printf("The original value: %u\n", myVal);

    // XOR the values
    unsigned int result = MASK ^ myVal;
    printf("Result of XOR: %u\n", result);
    return 0;
}