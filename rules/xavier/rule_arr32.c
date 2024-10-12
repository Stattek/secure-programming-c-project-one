/**
    Author: Xavier Zamora
    Sumary: ARR32-C, ensure size arguments for variable length arrays are in a valid range
    https://wiki.sei.cmu.edu/confluence/display/c/ARR32-C.+Ensure+size+arguments+for+variable+length+arrays+are+in+a+valid+range
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000  // defining maximum size for array

int main() {
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // size is invalid
    if (size <= 0 || size > MAX_SIZE)
    {
        printf("Error: Size must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = i * 2;
    }

    printf("Array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return 0;
}
