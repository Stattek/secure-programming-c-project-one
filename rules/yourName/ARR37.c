/*
Description: Rule Arr37-C states do not add or subtract an integer to a pointer to a non-array object. This rule mainly makes sure that if you are going to perform
    addition or subtraction of an integer you should not use a pointer to an object that is not an array and instead should use an array.

Why it is Important: This rule is important because if this rule is not followed you could get values that are part of some other structure because memebers of a
    structure are not guarnteed to be contiguous so they might be seperated from one another.


*/
#include <stdio.h>
#include <stdlib.h>

struct toyota{
    int models[4];
};

int main(){
    struct toyota my_toyotas = {.models[0] = 2012,.models[1] = 2015,.models[2] = 2020,.models[3] = 2024};
    int total = 0;
    for(int i = 0; i < 4; i ++){
        total += my_toyotas.models[i];
    }
    double average_age = (double)total/4;
    printf("Average age of car: %.1f", average_age);

    return 0;
}
