/**
 * Author: Colton Longstreth
 * Summary: Rule STR34-C example working code
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char string[12] = "Test";
    int sum = 0;
    // runs through string and takes the int value to add to sum but following the rule by casting to unsigned char first
    for (int i = 0; i < sizeof(string) / sizeof(string[0]); i++)
    {
        sum += (unsigned char)string[i];
    }
    printf("Sum of characters: %d", sum);
    return 0;
}
