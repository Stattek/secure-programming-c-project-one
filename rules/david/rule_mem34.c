/**
 * Author: David Slay
 * Summary: Rule MEM34-C example working code
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MY_STRING_LENGTH 25

int main(void)
{
    char *myHeapStr = NULL;

    // allocate memory on the heap
    myHeapStr = malloc(MY_STRING_LENGTH);
    if (myHeapStr == NULL)
    {
        printf("String not allocated by malloc.");
        // exit so we don't possibly try to free memory that wasn't dynamically allocated
        return 1;
    }

    // get user input string
    fgets(myHeapStr, MY_STRING_LENGTH, stdin);

    printf("My string on the heap: %s\n", myHeapStr);
    // only freeing the memory that was dynamically allocated
    free(myHeapStr);
    
    return 0;
}
