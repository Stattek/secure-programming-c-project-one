/**
 * Author: David Slay
 * Summary: Rule MEM05-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MY_BUFFER_SIZE 1024

// TODO: doc
bool writeInputToFile(FILE *dstFile, size_t bufSize)
{
    if (bufSize <= 0)
    {
        // error
        return true;
    }

    char *curStr = malloc(bufSize);
    if (!curStr)
    {
        printf("Could not allocate string\n");
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
            printf("Error writing to file\n");
            return true;
        }

        if (printNewLine)
        {
            // print the newline character if we removed it earlier
            err = fputs("\n", dstFile);
            if (err == EOF)
            {
                printf("Error writing to file\n");
                return true;
            }
        }
    }

    free(curStr);

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