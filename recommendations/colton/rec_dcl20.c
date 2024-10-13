/**
 * Author: Colton Longstreth
 * Summary: Rule DCL20-C example working code
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief prints a test statement
 */
void printStatement(void)
{
    printf("Statement inside function\n");
};

int main(void)
{
    // calls the test statement
    printStatement();

    return 0;
}
