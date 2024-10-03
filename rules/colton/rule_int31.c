/*
Description: Rule INT31-C states that you should make sure that when you convert an integer that you do not lose or misrepresent any data. This means that every 
    time that you convert some type of integer you must ensure that there would not be a change in how that data is represented. An example of this is making 
    sure that when you change a signed int to an unsigned int that there is no loss of meaning such as going from a negative number to a positive number.

Why it is Important: The reason that this rule is important is because errors in truncation of integers because this can lead to attackers being able to use a buffer
    overflow attack on the system which would allow the attack to execute their own code in the system.

*/
#include <stdlib.h>
#include <stdio.h>

int main(){
    int number_entered;
    //take user input
    printf("Enter number to get the absolute value: ");
    scanf("%d",&number_entered);
    //check if negative before conversion (Rule)
    if(number_entered < 0){
        number_entered = number_entered*(-1);
    }
    //convert to an unsigned int 
    size_t absolute_value = (size_t) number_entered;
    printf("Absolute Number: %d",absolute_value);

    return 0;
}
