/**
 * @file CON40-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates how to preserve atomicity of atomic value
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdatomic.h>
#include <stdio.h>

/**
 * @brief return the square of atomic n
 *
 * @param n the number to square
 * @returns the squared number
 */
int getSquare(int n)
{
  // CON40-C: Do not refer to an atomic variable twice in an expression
  // avoided refering to atomic var twice in expression
  // pass atomic var as parameter instead to retain atomic nature
  return n * n;
}

int main(void)
{
  atomic_int n = ATOMIC_VAR_INIT(5);

  printf("n^2 is: %d\n", getSquare(n));

  return 0;
}