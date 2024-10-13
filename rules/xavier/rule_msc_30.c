/**
 * @file rule_msc_30.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief MSC30: Do not use the rand() function for generating pseudorandom numbers
 * @version 1.0
 * @date 2024-10-12
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 10

void generateRandomNumbersWrong(char *output, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        output[i] = '0' + (rand() % 10);
    }
    output[length] = '\0';
}

void generateRandomNumbersRight(char *output, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        output[i] = '0' + (random() % 10);
    }
    output[length] = '\0';
}

int main(void)
{
    char randomNumbersWrong[MAXIMUM + 1];
    char randomNumbersRight[MAXIMUM + 1];

    generateRandomNumbersRight(randomNumbersRight, MAXIMUM);
    generateRandomNumbersWrong(randomNumbersWrong, MAXIMUM);

    printf("Fake random numbers: %s\n", randomNumbersWrong);
    printf("Real random numbers: %s\n", randomNumbersRight);

    return 0;
}