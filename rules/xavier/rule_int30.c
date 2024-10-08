/**
    Author: Xavier Zamora
    Sumary: Rule INT30-C working code, ensure that unsigned int operations do not wrap
    https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void tooBig(unsigned int a, unsigned int b)
{
    unsigned int mult;
    if (UINT_MAX - a < b)
    {
        printf("ur number is too big\n");
    }
    else
    {
        mult = a * b;
        printf("here is ur number: %u\n", mult);
    }
}

int main()
{
    srand(time(0));
    
    unsigned int a = rand() % UINT_MAX * 1.5;
    unsigned int b = rand() % UINT_MAX * 1.5;
    tooBig(a, b);
    return 0;
}

