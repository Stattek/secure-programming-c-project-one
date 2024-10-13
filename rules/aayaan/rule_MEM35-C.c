/**
 * @file MEM35-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates allocating sufficent memory for object
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdlib.h>
#include <stdio.h>

void allocate_int_arr(size_t len) {
    int *arr;

    // MEM35-C: Allocate sufficient memory for an object
    // avoided allocating wrong size: sizeof(float)
    // compare with arr + SIZE instead to loop for each element
    arr = (int *)malloc(len * sizeof(int));
    
    //check for success
    if (arr == NULL) {
        perror("Error: failed to allocate memory");
        return;
    }

    // fill array
    for (size_t i = 0; i < len; i++) 
    {
        arr[i] = (int)i; 
    }


    for (size_t i = 0; i < len; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");


    free(arr);
}

int main() {
    
    size_t len;

    printf("Enter the length of the array: ");
    scanf("%zu", &len);

    allocate_int_arr(len);

    return 0;
}
