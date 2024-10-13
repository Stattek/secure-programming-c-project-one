/**
 * Author: Colton Longstreth
 * Summary: Rule STR30-C example working code
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // using char array instead of pointer because of rule to not modify string literals if using a pointer
    char character_name[16] = "Sally";
    printf("Character name is currently: %s\n", character_name);
    // showing change to the string but not breaking rule because it is not a string literal
    character_name[0] = 'B';
    character_name[1] = 'i';

    printf("New character name is: %s\n", character_name);

    return 0;
}
