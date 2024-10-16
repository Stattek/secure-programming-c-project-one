/**
 * Author: David Slay
 * Summary: Rule STR32-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

#define MY_STRING_LENGTH 20

int main(void)
{
    const char *originString = "abcdefghijklmnopqrstuvwxyz";
    char destString[MY_STRING_LENGTH + 1] = ""; // plus one for the null-terminating character

    // we can safely copy this many characters and truncate the originString, since it is longer
    // than the destString.
    strncpy(destString, originString, MY_STRING_LENGTH);

    /*
    Rule STR32-C: Do not pass a non-null-terminated character sequence to a library function that expects a string
    Pass a null-terminated string to printf(), which looks prints until it reaches a null-terminating character.
    This will prevent undefined behavior.
    */
    printf("%s\n", destString);
    return 0;
}
