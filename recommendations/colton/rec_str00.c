/*
Description: Recommendation STR00-C states that you should represent characters using an appropriate type. In essence this means that depending on how you use 
    characters you should use specific types of characters when initializing the entity to hold those characters.

Why it is important: This recommendation is important because if it is followed it can eliminate a large quantity of common programming errors many of which lead to
    different vulnerabilities in the system that they are are a part of.

*/
#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *file_pointer;
    int character;
    char file_name[100];

    printf("Enter file name:\n");
    scanf("%99s",file_name);

    file_pointer = fopen(file_name, "r"); 

    if (file_pointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((character = fgetc(file_pointer)) != EOF) {
        printf("%c", character);
    }

    fclose(file_pointer);
    return 0;
}
