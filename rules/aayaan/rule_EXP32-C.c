/**
 * @file EXP32-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates volitile type elements
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    static volatile int val = 10;

    static int *ptr;
    // causes a warning, should not have non volitile refrence to volitile type
    ptr = &val;

    // EXP32-C: Do not access a volatile object through a nonvolatile reference
    // avoided using *ptr == 10
    // compare with direct refrence to volatile object val
    if (val == 10)
    {
        printf("100/10 is %d.\n", val);
    }
}