/**
    Author: Xavier Zamora
    Sumary: Rule MSC41-C working code, never hard code sensitive information
    https://wiki.sei.cmu.edu/confluence/display/c/MSC41-C.+Never+hard+code+sensitive+information
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PASSWORD "ILoveCSoMuch"

int main()
{
    // lines 15 and 18 are litearlly just for formatting to ensure whatever u type matches exactly
    char passwordAttempt[strlen(PASSWORD) + 1];
    printf("password attempt:\n");
    fgets(passwordAttempt, sizeof(passwordAttempt), stdin);
    passwordAttempt[strcspn(passwordAttempt, "\n")] = 0;

    // compare the two strings and store the output into an int
    int compare = strcmp(passwordAttempt, PASSWORD);

    // immediately change passwordAttempt to a string of zeroes
    memset(passwordAttempt, sizeof(passwordAttempt), 0);

    if (!compare)
    {
        printf("correct password yippee");
        return 0;
    }
    else
    {
        printf("wrong password go away");
        return 1;
    }
}