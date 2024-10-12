/**
 * @file rec_exp15.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief EXP15: Do not place a semicolon on the same line as an if, for, or while statement
 * @version 1.0
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;

    // this semicolon (v) will cause an infinite loop!
    /*while (count < 5);
    {
        printf("Count: %d\n", count);
        count++;
    }*/

    while (count <= 3)
    {
        printf("Count: %d\n", count);
        count++;
    }

    printf("done");
    return 0;
}