/**
 * Author: Xavier Zamora
 * Summary: Rule MEM30-C working code, don't access freed memory
    https://wiki.sei.cmu.edu/confluence/display/c/MEM30-C.+Do+not+access+freed+memory
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int));
    int *ptr_two = (int *)malloc(sizeof(int));

    if (ptr == NULL || ptr_two == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }  

    // give a value to ptr and access it
    // all good
    *ptr = 7;
    printf("Value before freeing memory: %d\n", *ptr);

    // free the ptr and access it
    // not all good, results in garbage being spit out (undefined behavior)
    free(ptr);
    printf("Attempting to access freed memory: %d\n", *ptr);

    // give a value to ptr_two and access it
    // all good
    *ptr_two == 25;
    printf("Value before freeing memory: %d\n", *ptr_two);

    // todo: fix


    return 0;
}