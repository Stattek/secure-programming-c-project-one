/**
 * @file rec_pre02.c
 * @author Aayaan Shaikh
 * @brief demonstrates using parenthesis for proper order of operations in macro expansion
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>

// PRE02-C: Macro replacement lists should be parenthesized
// avoided wrong ouput of 64 by way of (16 / 2) * 2 * 2 * 2
// used parenthesis for operation order: 16 / (2 * 2 * 2 * 2)
#define TESSERACTED(X) ((X) * (X) * (X) * (X))

int main(void)
{
    printf("160 divided by 2 to the fourth is: %d\n", 16 / TESSERACTED(2));

    return 0;
}