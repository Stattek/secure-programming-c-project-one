/**
 * Author: David Slay
 * Summary: Recommendation MEM05-C, recommendation MEM00-C, and
 * rule MEM34-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MY_BUFFER_SIZE 1024

/**
 * @brief Safely takes and writes user input to a file.
 *
 * @param dstFile The destination file to write to.
 * @param bufSize The buffer size for writing to file.
 *
 * @returns true on error, false otherwise.
 */
bool writeInputToFile(FILE *dstFile, size_t bufSize)
{
    if (bufSize <= 0 || !dstFile)
    {
        // error
        return true;
    }

    /*
    Recommendation MEM05-C: Avoid large stack allocations
    Done by allocating a large string on the heap for writing to a file.
    */
    char *curStr = malloc(bufSize);
    if (!curStr)
    {
        fprintf(stderr, "Could not allocate string\n");
        return true;
    }

    printf("Type your document below or type \":q\" on a new line\n\n");
    while (fgets(curStr, bufSize, stdin))
    {
        size_t curStrLen = strlen(curStr);

        bool printNewLine = false;
        if (curStr[curStrLen - 1] == '\n')
        {
            // set the newline character to the null-terminating character
            curStr[curStrLen - 1] = '\0';
            printNewLine = true; // we should print the new line character later
        }
        if (strncmp(curStr, ":q", bufSize) == 0)
        {
            // break from the loop if the user types ":q" on a new line
            break;
        }

        // print the string that we read
        int err = fputs(curStr, dstFile);
        if (err == EOF)
        {
            fprintf(stderr, "Error writing to file\n");
            return true;
        }

        if (printNewLine)
        {
            // print the newline character if we removed it earlier
            err = fputs("\n", dstFile);
            if (err == EOF)
            {
                fprintf(stderr, "Error writing to file\n");
                return true;
            }
        }
    }

    /*
    Recommendation MEM00-C: Allocate and free memory in the same module, at the same level of abstraction
    free dynamically allocated memory on the same level of abstraction

    Rule MEM34-C:Only free memory allocated dynamically
    Only freeing dynamically allocated memory, as this string can only possibly be on the heap.
    */
    free(curStr);
    curStr = NULL;

    // if we get here, there is no error
    return false;
}

int main(void)
{
    FILE *output = fopen("rec_mem05_output.txt", "w");

    // write user input to file
    writeInputToFile(output, MY_BUFFER_SIZE);

    fclose(output);
    return 0;
}