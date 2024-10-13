
/**
 * @file INT07-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates how to properly use char for numeric values
 * @version 0.1
 * @date 2024-10-12
 *
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
  // INT07-C: Use only explicitly signed or unsigned char type for numeric values
  // avoided non-compliance by explicitly initalizing char as unsigned
  unsigned char exp = 2;

  int i = 7;

  printf("%d ^ %d = %f\n", i, exp, pow(i, exp));
}