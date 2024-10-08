
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
