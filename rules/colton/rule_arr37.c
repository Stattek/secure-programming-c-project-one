/**
 * Author: Colton Longstreth
 * Summary: Rule ARR37-C example working code
 */
#include <stdio.h>
#include <stdlib.h>

struct Toyota
{
    int models[4];
};

int main(void)
{
    struct Toyota my_toyotas = {.models[0] = 2012, .models[1] = 2015, .models[2] = 2020, .models[3] = 2024};
    int total = 0;
    // loop to go through the struct
    for (int i = 0; i < 4; i++)
    {
        total += my_toyotas.models[i];
    }
    double average_age = (double)total / 4;
    printf("Average age of car: %.1f\n", average_age);

    return 0;
}
