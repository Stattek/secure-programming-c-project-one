/**
 * Author: David Slay
 * Summary: Rule FIO34-C and rule FIO38-C example working code
 */
#include <stdio.h>

int main(void)
{
    // create a file
    FILE *inputFile = fopen("fio34_fio38.txt", "r");
    if (!inputFile)
    {
        fprintf(stderr, "Error in opening file.");
        return 1;
    }

    /*
    Rule FIO38-C: Do not copy a FILE object
    Does not copy the FILE object, only takes a copy of the pointer to it.
    */
    FILE *readFile = inputFile;

    printf("Text read from fio34_fio38.txt:\n");
    printf("*************************\n");

    char curChar; // for reading from file

    /*
    Rule FIO34-C: Distinguish between characters read from a file and EOF or WEOF
    Loop while we haven't gotten an EOF character and make sure it was a real EOF by using feof() and ferror().
    */
    do
    {
        curChar = fgetc(readFile);

        if (curChar != EOF || (!feof(readFile) && !ferror(readFile)))
        {
            printf("%c", curChar);
        }
    } while (curChar != EOF || (!feof(readFile) && !ferror(readFile)));
    printf("\n");

    // close the file
    fclose(readFile);
    return 0;
}
