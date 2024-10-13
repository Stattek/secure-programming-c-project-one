/**
 * @file rec_arr02.c
 * @author Xavier Zamora (xzamora@iltsu.edu)
 * @brief
 * @version 1.0
 * @date 2024-10-12
 *
 */
#include <stdio.h>

int main(void)
{
    // implicitly defined size of 6
    char message1[] = "hi :D";

    // explicitly defined size of 6
    char message2[6] = "hi :)";

    // printing both messages out
    printf("%s\n", message1);
    printf("%s\n", message2);
}