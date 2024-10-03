/*
Description: Rule Mem31-C states that should free dynamically allocated memory when it is no longer needed. This essentially means that once you are done using
    something on the heap, such as a pointer, you should free that space that it was using.

Why it is important: This rule is important because if you do not free memory that was allocated then it can cause the system to not be able to use that memory
    in the future as that memory still thinks it is still being used. Also, if you do not free memory that you allocated an external actor could get access to that
    memory to see what was there previously giving them information that they should not have.



*/
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int *int_pointer = (int *)malloc(5*sizeof(int));
    int product = 0;
    for(int i = 0; i < 5; i++){
        printf("Enter digit to get multiplied: ");
        scanf("%d",&int_pointer[i]);
    }

    product = int_pointer[0] * int_pointer[1] *int_pointer[2] * int_pointer[3] * int_pointer[4];

    printf("Product is: %d", product);

    free(int_pointer);
    return 0;
}
