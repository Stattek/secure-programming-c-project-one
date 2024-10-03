/**
 * Author: David Slay
 * Summary: Rule FIO38-C example working code
 */
#include <stdio.h>
#include <string.h>

#define MY_STRING_LENGTH 1024

int main(void)
{
    FILE *inputFile = fopen("./fio38.txt", "r");
    if (!inputFile)
    {
        fprintf(stderr, "Error in opening file.");
        return 1;
    }

    // does not copy the FILE object, only takes a copy of the pointer to it
    FILE *readFile = inputFile;

    char buf[MY_STRING_LENGTH];
    memset(buf, 0, MY_STRING_LENGTH);
    char *curPtr = NULL;

    // print out the file
    do
    {
        // get next string from the file
        curPtr = fgets(buf, MY_STRING_LENGTH, readFile);

        if (curPtr != NULL)
        {
            printf("%s", buf);
            // clear buffer
            memset(buf, 0, MY_STRING_LENGTH);
        }
    } while (curPtr != NULL);

    fclose(inputFile);
    return 0;
}
