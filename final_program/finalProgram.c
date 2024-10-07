/**
 * Author: David Slay,
 * Summary: Final program for program one
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

// TODO: doc
bool writeFile(FILE *dstFile, int bufSize)
{
    if (!dstFile || bufSize <= 0)
    {
        return true; // error
    }

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

    free(curStr);
    curStr = NULL;
}

// TODO: doc
void promptUser(void)
{
    // FUTURE: for writing a file, let the user specify the name (sanitize it to satisfy a rule)
    printf("Choose an option:\n\t1. Read a file\n\t2. Write a file\n\t");
}

int main(void)
{
    promptUser();

    FILE *outFile = fopen("outfile.txt", "w");

    writeFile(outFile, BUFFER_SIZE);

    return 0;
}