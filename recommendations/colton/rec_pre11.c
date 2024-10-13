/**
 * Author: Colton Longstreth
 * Summary: Recommendation PRE11-C example working code
 */

#include <stdio.h>

#define power_of_two(power)         \
    {                               \
        sum = 1;                    \
        for (i = 0; i < power; i++) \
        {                           \
            sum = sum * 2;          \
        }                           \
    }

int i;
int sum;

int main(void)
{
    int power_of_two_wanted;
    // takes user input for wanted power of 2
    printf("Enter power of 2 desired: ");
    scanf("%d", &power_of_two_wanted);

    // uses macro to calculate power of 2
    power_of_two(power_of_two_wanted);
    // prints value
    printf("Value: %d\n", sum);

    return 0;
}
