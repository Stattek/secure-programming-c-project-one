
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int small_number = 12314213;
    long long larger_number = 135135236923581294;

    if((long long)small_number + small_number < larger_number){
        printf("Small number times 2 is less than the large number.");
    }


    return 0;
}
