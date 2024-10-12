/**
 * Author: Waleed
 * Summary: In this code, the program reads a file name from the user and validates
 * it to prevent path traversal and absolute path usage. It constructs a safe file path
 * by prefixing a known directory and ensures memory allocation is handled correctly.
 * This careful handling of file names mitigates security risks associated with file operations.
 */
#define _GNU_SOURCE // For asprintf()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 * @brief This function checks if a given filename is valid.
 *
 * @param filename
 * @return int
 */
int is_valid_filename(const char *filename)
{
    // Simple validation: filename should not contain ".." or start with '/'
    if (strstr(filename, "..") != NULL || filename[0] == '/')
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    char input_filename[PATH_MAX];

    printf("Enter the filename: ");
    if (fgets(input_filename, sizeof(input_filename), stdin) != NULL)
    {
        // Remove newline character
        input_filename[strcspn(input_filename, "\n")] = '\0';

        if (!is_valid_filename(input_filename))
        {
            fprintf(stderr, "Invalid filename.\n");
            return 1;
        }

        // Safely construct the full file path
        char *file_path = NULL;
        if (asprintf(&file_path, "./data/%s", input_filename) == -1)
        {
            fprintf(stderr, "Memory allocation error.\n");
            return 1;
        }

        FILE *file = fopen(file_path, "r");
        free(file_path); // Free allocated memory

        if (file == NULL)
        {
            perror("Error opening file");
            return 1;
        }

        // Perform file operations here

        fclose(file);
    }
    else
    {
        fprintf(stderr, "Error reading filename.\n");
        return 1;
    }

    return 0;
}