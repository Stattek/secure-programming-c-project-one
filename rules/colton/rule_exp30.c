/*
Description: Rule XP30-C states that you should not depend on the order of side effects for the your opperations. This seems to particularly be important when dealing
    with arrays. So, you always want to make sure there is no ambiguity in how something will happen if there are side effects which may lead you to increment or 
    decrement your counter before you use it as an index for an array.

Why it is Important: This is important because not following this rule can cause confusion in how the program will work creating bugs or causing the code to not
    follow other rules such as not using an out of bounds index,Arr30. This kind of error can cause very unexpected values to appear which can cause unexpected 
    behavior in the program.


*/
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
