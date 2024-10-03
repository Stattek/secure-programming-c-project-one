/*
Description: Rule Arr30-C states that you should not use or create any out of bound pointers or array indices.This means that you need you make sure that you 
    never use a value that for a pointer or array index that puts it out of range of what the logical limit of that pointer or array should be.

Why it is important: This rule is important because if not followed then at best you get junk values from the out of bounds values and at worst you can change
    values that are being used elsewhere breaking the application and if an attacker is allowed to change the out of bounds value then it can cause 
    severe security problems.

*/
#include <stdio.h>


int main(void){

    int int_array1[3][4];
    int int_array2[4][2];
    //adding values to array 1
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            int_array1[i][j] = j + i;
        }
    }
    //adding values to array 2
    for(int k = 0; k < 4; k++){
        for(int l = 0; l < 2; l++){
            int_array2[k][l] = k + l;
        }
    }
    //matrix multiplication
    int final_array[3][2];
    for(int m = 0; m < 3; m++){
        for(int n = 0; n < 2; n++){
            final_array[m][n] = 0;
            for(int t = 0; t < 4; t++){
                final_array[m][n] += int_array1[m][t] * int_array2[t][n];
            }
            printf("%d\t", final_array[m][n]);
        }
        printf("\n");
    }
    
    return 0;
}
