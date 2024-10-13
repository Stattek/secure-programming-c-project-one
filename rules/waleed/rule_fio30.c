/**
 * Author: Waleed
 * Summary: Here, the program uses a fixed format string in `printf`, preventing any unintended behavior from user input.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50];

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) != NULL)
    {
        // Remove newline character if present
        name[strcspn(name, "\n")] = '\0';

        // Use a fixed format string
        printf("Hello, %s!\n", name);
    }
    else
    {
        fprintf(stderr, "Input error.\n");
    }

    return 0;
}