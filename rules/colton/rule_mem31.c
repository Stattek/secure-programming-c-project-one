
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
