/**
 * Author: Waleed
 * Summary: The code checks if the input is nonempty before proceeding, ensuring it does not operate on empty data.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];

    printf("Enter some text: ");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        if (input[0] != '\0')
        {
            printf("You entered: %s\n", input);
        }
        else
        {
            fprintf(stderr, "No input provided.\n");
        }
    }
    else
    {
        fprintf(stderr, "Error reading input.\n");
    }

    return 0;
}