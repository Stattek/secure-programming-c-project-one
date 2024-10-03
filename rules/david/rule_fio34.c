/**
 * Author: David Slay
 * Summary: Rule FIO34-C example working code
 */
#include <stdio.h>

int main(void)
{
    // create a file
    FILE *inputFile = fopen("fio34.txt", "r");

    printf("Text read from fio34.txt:\n");
    printf("*************************\n");

    char curChar; // for reading from file
    // Loop while we haven't gotten an EOF character and make sure it was a real EOF using feof() and ferror()
    do
    {
        curChar = fgetc(inputFile);

        if (curChar != EOF || (!feof(inputFile) && !ferror(inputFile)))
        {
            printf("%c", curChar);
        }
    } while (curChar != EOF || (!feof(inputFile) && !ferror(inputFile)));
    printf("\n");

    // close the file
    fclose(inputFile);
    return 0;
}
