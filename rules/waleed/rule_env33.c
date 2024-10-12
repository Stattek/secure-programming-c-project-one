/**
 * Author: Waleed
 * Summary: Instead of calling `system("rm example.txt")`, the `remove()` 
 * function is used to delete the file safely.
 */
#include <stdio.h>

int main(void)
{
    const char *filename = "example.txt";

    if (remove(filename) == 0)
    {
        printf("Successfully deleted %s\n", filename);
    }
    else
    {
        perror("Error deleting file");
    }

    return 0;
}