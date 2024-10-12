/**
 * Author: Waleed
 * Summary: Seeding the PRNG with the current time ensures that the sequence of numbers is different each time the program runs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Seed the PRNG with the current time
    srand((unsigned int)time(NULL));

    int random_number = rand();
    printf("Random number: %d\n", random_number);

    return 0;
}