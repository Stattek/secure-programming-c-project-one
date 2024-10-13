/**
 * Author: David Slay
 * Summary: Recommendation STR02-C and rule STR38-c example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define DIRECTORY_STRING_LENGTH 1024

/**
 * @brief Checks that a string is valid and only contains characters in the
 * specified character string.
 *
 * @param targetStr The string to validate.
 * @param validCharacters The valid characters.
 */
bool isValidString(char *targetStr, const char *validCharacters)
{
    bool isValid = false;

    /*
    Rule STR38-C: Do not confuse narrow and wide character strings and functions
    This code does not confuse wide character string functions with narrow character string functions,
    as this uses the strlen() function for narrow strings on a narrow string.
    */
    char *lastCharPtr = targetStr + strlen(targetStr) - 1; // find the last character of the string
    if (lastCharPtr && *lastCharPtr == '\n')
    {
        *lastCharPtr = '\0'; // make this the new end of the string if it's a newline char
    }

    // find the length of the string until we find a character that is invalid
    size_t numValidChars = strspn(targetStr, validCharacters);
    if (numValidChars == strlen(targetStr))
    {
        // if our input string is all correct characters then it is sanitized
        isValid = true;
    }

    return isValid;
}

int main(void)
{
    static const char VALID_CHARACTERS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/._";

    char directoryStr[DIRECTORY_STRING_LENGTH];
    memset(directoryStr, 0, DIRECTORY_STRING_LENGTH);
    char *readStrPtr;

    /*
    Recommendation STR02-C: Sanitize data passed to complex subsystems
    This is an example of this recommendation, as the following loop ensures that the string read from the user
    is sanitized for use with more a more complicated subsystem, as it will be used by ls.*/
    bool nameIsSanitized = false;
    do
    {
        printf("Enter a directory to use ls on: ");
        // read from user
        readStrPtr = fgets(directoryStr, DIRECTORY_STRING_LENGTH, stdin);

        // check that string is sanitized
        nameIsSanitized = isValidString(readStrPtr, VALID_CHARACTERS);
    } while (!nameIsSanitized);

    printf("\n\nOutput of ls:\n");

    // execute ls on the directory specified
    int err = execlp("/bin/ls", "ls", directoryStr, (char *)0);
    if (err == -1)
    {
        fprintf(stderr, "Error in executing ls\n");
    }
    return 0;
}