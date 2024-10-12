/**
 * @file rec_pre01.c
 * @author Xavier Zamora (xzamora@ilstu.edu)
 * @brief PRE01: Use parentheses within macros around parameter names
 * @version 1.0
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#define SQUAREWRONG(X) (X * X)
#define SQUARERIGHT(X) ((X) * (X))

int main()
{
    int a = 7;
    int resultWrong = SQUAREWRONG(a + 1);
    int resultRight = SQUARERIGHT(a + 1);

    printf("Wrong result: %d\n", resultWrong);
    printf("Right result: %d\n", resultRight);

    return 0;
}