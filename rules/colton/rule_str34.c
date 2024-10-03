/*
Description: Rule Str34-C states that you should cast characters to unsigned char before converting to larger int sizes. So this means if you want to covert a
    char into an int, a larger size, then you should first convert to an unsigned char before conversion to an int.

Why it is Important: This is an important rule because this has caused vulnerabilities in the past in bash and can cause severe vulnerabilities in the system and
    can be very easy to miss making it harder to debug or find the reason for a vulnerability.


*/
#include <stdlib.h>
#include <stdio.h>

int main(void){
    char string[12] = "Test";
    int sum = 0;
    for(int i = 0; i < sizeof(string)/sizeof(string[0]); i++){
        sum += (unsigned char)string[i];
    }
    printf("Sum of characters: %d",sum);
    return 0;
}
