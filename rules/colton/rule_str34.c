
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
