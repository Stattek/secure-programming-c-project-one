/*
Description: Recommendation INT18-C states that you should evaluate integer expressions in a larger size before comparing or assigning to that size of integer.
    Basically, if you are going to compare some integer to a larger sized integer you should either upcast part of the integer expression to work in that size of 
    space or rearrange the expression so that you still work in the correct size space for the integers you are working with.

Why it is important: This recommendation important because if not followed it can cause the expression to wrap on itself giving wrong values and it can also cause
    buffer overflows because there is insufficient space created which is a security vulnerability.

*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int small_number = 12314213;
    long long larger_number = 135135236923581294;

    if((long long)small_number + small_number < larger_number){
        printf("Small number times 2 is less than the large number.");
    }


    return 0;
}
