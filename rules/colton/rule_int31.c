/**
 * Author: Colton Longstreth
 * Summary: Rule INT31-C example working code
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int number_entered;
    // take user input
    printf("Enter number to get the absolute value: ");
    scanf("%d", &number_entered);
    // check if negative before conversion (Rule)
    if (number_entered < 0)
    {
        number_entered = number_entered * (-1);
    }
    // convert to an unsigned int
    size_t absolute_value = (size_t)number_entered;
    printf("Absolute Number: %d", absolute_value);

    return 0;
}
