/**
 * Author: Waleed
 * Summary: This code checks that the destination buffer is large enough before copying, preventing invalid pointers from being formed during the `strcpy` operation.
 */
#include <string.h>
#include <stdio.h>

int main(void)
{
    char source[] = "Hello, World!";
    char destination[20];

    // Ensure the destination buffer is large enough
    if (sizeof(destination) > strlen(source))
    {
        strcpy(destination, source);
        printf("Copied string: %s\n", destination);
    }
    else
    {
        fprintf(stderr, "Destination buffer is too small.\n");
    }

    return 0;
}