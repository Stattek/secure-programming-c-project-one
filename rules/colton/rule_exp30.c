
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number_holder = 0;
    ///takes user input
    printf("Enter number to have 1 added to and then doubled: ");
    scanf("%d",&number_holder);
    ///rule is being followed here as this is a non side effect way of adding one and then multiplying the integer
    number_holder += 1;
    number_holder = number_holder * 2;

    printf("Number after operations: %d", number_holder);

    return 0;
}
