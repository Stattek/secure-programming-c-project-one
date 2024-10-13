/**
 * Author: Colton Longstreth
 * Summary: Rule INT18-C example working code
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // initializes 2 numbers to compare
    int small_number = 12314213;
    long long larger_number = 135135236923581294;
    // comparing the 2 numbers
    if ((long long)small_number + small_number < larger_number)
    {
        printf("Small number times 2 is less than the large number.\n");
    }

    return 0;
}
