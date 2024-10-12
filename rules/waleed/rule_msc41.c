/**
 * Author: Waleed
 * Summary: The program prompts the user for a password instead of using a hard-coded value.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[100];

    printf("Enter your password: ");
    if (fgets(password, sizeof(password), stdin) != NULL)
    {
        // Remove newline character
        password[strcspn(password, "\n")] = '\0';

        // Proceed with authentication (not implemented here)
        printf("Password received.\n");
    }
    else
    {
        fprintf(stderr, "Error reading password.\n");
    }

    return 0;
}