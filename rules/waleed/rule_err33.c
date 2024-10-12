/**
 * Author: Waleed
 * Summary: In this example, the program checks the return values of `fopen` and 
 * `fclose` to ensure that file operations are successful, handling any errors appropriately.
 */
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Perform file operations here

    if (fclose(file) != 0)
    {
        perror("Error closing file");
        return 1;
    }

    return 0;
}