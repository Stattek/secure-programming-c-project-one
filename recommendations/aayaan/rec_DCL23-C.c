/**
 * @file DCL23-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates unique identefiers for extern variables abstracted for many implementations
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>

int main()
{
  // DCL23-C: Guarantee that mutually visible identifiers are unique
  // avoided non-compliance by not having unique portion of identifier in back of id
  // compliance by having unique portion of identifier in front of id;
  extern int *a_test_world_map_id_region_state_000010100101011010;
  extern int *b_test_world_map_id_region_state_000010100101011010;
}