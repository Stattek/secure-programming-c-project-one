/**
 * Author: David Slay
 * Summary: Rule ENV32-C example working code
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Example function to show the order in which functions registered with
 * atexit() are called.
 */
void exit1(void)
{
    printf("This is from exit1().\n");
    return;
}

/**
 * @brief Example function to show the order in which functions registered with
 * atexit() are called.
 */
void exit2(void)
{
    printf("This is from exit2().\n");
    return;
}

/**
 * @brief Example function to show the order in which functions registered with
 * atexit() are called.
 */
void exit3(void)
{
    printf("This is from exit3().\n");
    return;
}

int main(void)
{
    // functions registered with atexit() should be called in reverse-order when the program exits
    if (atexit(exit1) || atexit(exit2) || atexit(exit3))
    {
        perror("Error registering function in atexit()");
        return 1;
    }

    printf("This is in main().\n");

    return 0;
}
