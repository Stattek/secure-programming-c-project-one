/*
Description: Rule Int33-C states that when doing division or operations with a remainder do no end up resulting in a scnario where you are dividing by 0. Essentially
    you need to check to make sure you are not dividing by zero or using zero when using % operator.

Why it is Important: This rule is important because if you do not follow this rule you can cause a divide by zero error which can crash your program abnormally and
    denial of service. 

*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int dividend = 0;
    printf("Enter the number used as the dividend: ");
    scanf("%d",&dividend);

    int divisor = 0;
    printf("Enter the number used as the divisor: ");
    scanf("%d",&divisor);

    if(divisor == 0){
        printf("Error, divisor cannot be zero. Enter new number to be divisor: ");
        scanf("%d",&divisor);
    }
    double result = (double)dividend/(double)divisor;
    printf("The result is: %.3f",result);
    return 0;
}
