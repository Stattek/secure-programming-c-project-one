/**
    Author: Xavier Zamora
    Sumary: Rule EXP34-C working code, do not dereference null pointers (lol)
    https://wiki.sei.cmu.edu/confluence/display/c/EXP34-C.+Do+not+dereference+null+pointers
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // creating a null ptr
    int *ptr = NULL;

    // below is attempting to dereference a null ptr, very not good and can lead to undefined behavior
    // commented bc i dont want my code to explode
    // *ptr = 10;

    // below is checking if ptr is null before attempting to dereference
    if (ptr == NULL)
    {
        printf("don't dereference a null ptr!");
        return 1;
    }
    else
    {
        printf("thank u for following the rules :)");
        return 0;
    }
}