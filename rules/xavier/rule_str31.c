/**
 * @file rule_str31.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief STR31: ensure storage for strings has sufficient space for character data
 * @version 1.0
 * @date 2024-10-13
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // c doesnt have strings built in so we need array of characters
    char hello[] = "hello world";
    printf("%d\n", hello[11]);

    // attempting to copy one string to another that does not hold enough space
    char failure[5];

    int i;
    for (i = 0; i <= 11; i++)
    {
        failure[i] = hello[i];
    }

    // checking every character in failure
    // this only prints out five characters, not every character from hello got copied to failure
    for (i = 0; i <= 11; i++)
    {
        printf("%d\n", failure[i]);
    }

    return 0;
}