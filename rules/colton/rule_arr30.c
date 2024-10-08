
#include <stdio.h>


int main(void){

    int int_array1[3][4];
    int int_array2[4][2];
    ///adding values to array 1
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            int_array1[i][j] = j + i;
        }
    }
    ///adding values to array 2
    for(int k = 0; k < 4; k++){
        for(int l = 0; l < 2; l++){
            int_array2[k][l] = k + l;
        }
    }
    ///matrix multiplication
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
