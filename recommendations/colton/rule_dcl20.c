/*
Description: Recommendation DCL20-C states that if a function takes no arguements you should explicitly specify that by putting void in the
    parameter list. So, if you ever create a function that does not take paramenters you should still add void where the parameters would go.

Why it is important: This recommendation is important because if not followed it can cause errors in use from programmers working with the function
    which could lead to sensitive information desclosure because if a function is called with a parameter and does not take one but does not have void
    for its parameter list then the parameter passed can still be put on the stack which an attacker could potentially access.

*/

#include <stdio.h>
#include <stdlib.h>

void printStatement(void){
    printf("Statement inside function");
};


int main(){

    printStatement();

    return 0;
}
