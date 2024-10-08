
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number_holder = 0;
    printf("Enter number to have 1 added to and then doubled: ");
    scanf("%d",&number_holder);

    number_holder += 1;
    number_holder = number_holder * 2;

    printf("Number after operations: %d", number_holder);

    return 0;
}
