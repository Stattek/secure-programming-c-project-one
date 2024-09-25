/**
 * Author: David Slay
 * Summary: Rule STR32-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MY_STRING_LENGTH 20

int main()
{
    const char *originString = "abcdefghijklmnopqrstuvwxyz";
    char destString[MY_STRING_LENGTH + 1] = ""; // plus one for the null-terminating character

    // we can safely copy this many characters and have a null-terminating character at the end of the string
    strncpy(destString, originString, MY_STRING_LENGTH);

    // This string is null-terminated, so there should be no problems printing it
    printf("%s\n", destString);
    return 0;
}
