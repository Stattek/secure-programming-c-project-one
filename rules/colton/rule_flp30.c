/*
Description: Rule FLP30-C states that you should not use floating point numbers for counters of loops. So, you should never use a float in a for loop based on this
    rule.

Why it is Important: This rule is important because if you do not follow this rule your loops can have unexpected behavior such as never ending loops or loops that
    have a variance in how many interations will be completed.


*/
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int int_array[] = {1,3,5,7,9,11};

    for(int i = 0; i < sizeof(int_array)/sizeof(int_array[0]); i++){
        printf("%d \t",int_array[i]);
    }

    return 0;
}
