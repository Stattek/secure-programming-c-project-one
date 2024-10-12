/**
 * @file MEM35-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates allocating sufficent memory for object
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdlib.h>
#include <stdio.h>

void allocate_int_arr(size_t len)
{
  int *arr;

  // MEM35-C: Allocate sufficient memory for an object
  // avoided allocating wrong size: sizeof(float)
  // compare with arr + SIZE instead to loop for each element
  arr = (int *)malloc(len * sizeof(int));

  free(arr);
}