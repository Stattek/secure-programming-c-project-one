/*
Description: Rule STR30-C states that you should not try to modify string literals. This essentially means that you should not try to modify a char pointer and if
    you do want to be able to modify a char pointer than you should use a char array instead, which allows you to change the string it is holding.

Why it is important: It is important because very often when modifiying a string literal it results in an access violation becuase of how string literals are usually
    stored which is in a read only state. This type of attack where the attacker is able to change string literals could lead to abnormal program behavior and 
    potentially be an avenue for DOS attacks.

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char character_name[16] = "Sally";
    printf("Character name is currently: %s\n",character_name);
    
    character_name[0] = 'B';
    character_name[1] = 'i';

    printf("New character name is: %s", character_name);

    return 0;
}
