/**
 * @file DCL23-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates unique identifiers for extern variables abstracted for many implementations
 * @version 0.1
 * @date 2024-10-12
 *
 */

#include <stdio.h>

int blood_type_a_positive_variable = 1;
int blood_type_b_positive_variable = 2;

// DCL23-C: Guarantee that mutually visible identifiers are unique
// avoided non-compliance by not having unique portion of identifier in back of id
// compliance by having unique portion of identifier in first 31 charcters of id
extern int *unique_blood_type_a_positive_state_variable_identifier;
extern int *unique_blood_type_b_positive_state_variable_identifier;

int main(void)
{

    int *unique_blood_type_a_positive_state_variable_identifier = &blood_type_a_positive_variable;
    int *unique_blood_type_b_positive_state_variable_identifier = &blood_type_b_positive_variable;

    printf("Value from unique_blood_type_a_positive_state_variable_identifier: %d\n",
           *unique_blood_type_a_positive_state_variable_identifier);
    printf("Value from unique_blood_type_b_positive_state_variable_identifier: %d\n",
           *unique_blood_type_b_positive_state_variable_identifier);

    return 0;
}
