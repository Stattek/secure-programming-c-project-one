
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char character_name[16] = "Sally";
    printf("Character name is currently: %s\n",character_name);
    
    character_name[0] = 'B';
    character_name[1] = 'i';

    printf("New character name is: %s", character_name);

    return 0;
}
