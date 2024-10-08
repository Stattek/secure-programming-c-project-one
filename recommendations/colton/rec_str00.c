
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
