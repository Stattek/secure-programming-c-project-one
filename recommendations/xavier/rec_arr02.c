/**
 * @file rec_arr02.c
 * @author Xavier Zamora (xzamora@iltsu.edu)
 * @brief 
 * @version 1.0
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main()
{
    // implicitly defined size of 6
    char message1[] = "hi :D";

    // explicitly defined size of 6
    char message2[] = "hi :)";

    printf("%s\n", message1);
    printf("%s\n", message2);

}