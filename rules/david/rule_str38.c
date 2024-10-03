/**
 * Author: David Slay
 * Summary: Rule STR38-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // string functions
#include <wchar.h>  // wide string functions

#define MY_STRING_LENGTH 25

int main(void)
{
    wchar_t wideCharStrSrc[MY_STRING_LENGTH + 1] = L"This is a wide string";
    wchar_t wideCharStrDst[MY_STRING_LENGTH + 1] = L"";

    // use wide string copy function
    wcsncpy(wideCharStrDst, wideCharStrSrc, MY_STRING_LENGTH);

    char charStrSrc[MY_STRING_LENGTH + 1] = "This is a string";
    char charStrDst[MY_STRING_LENGTH + 1] = "";

    // use normal string copy function
    strncpy(charStrDst, charStrSrc, MY_STRING_LENGTH);

    // get length of strings (using correct functions) before null-terminating character
    size_t wideCharLen = wcslen(wideCharStrDst);
    size_t charLen = strlen(charStrDst);

    // print out their lengths
    printf("Length of the wide string: %zu\nLength of normal string: %zu\n", wideCharLen, charLen);

    return 0;
}
