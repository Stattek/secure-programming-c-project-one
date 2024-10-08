
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int int_array[] = {1,3,5,7,9,11};

    for(int i = 0; i < sizeof(int_array)/sizeof(int_array[0]); i++){
        printf("%d \t",int_array[i]);
    }

    return 0;
}
