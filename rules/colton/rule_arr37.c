
#include <stdio.h>
#include <stdlib.h>

struct toyota{
    int models[4];
};

int main(void){
    struct toyota my_toyotas = {.models[0] = 2012,.models[1] = 2015,.models[2] = 2020,.models[3] = 2024};
    int total = 0;
    for(int i = 0; i < 4; i ++){
        total += my_toyotas.models[i];
    }
    double average_age = (double)total/4;
    printf("Average age of car: %.1f", average_age);

    return 0;
}
