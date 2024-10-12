/**
 * Author: Colton Longstreth
 * Summary: Rule STR00-C example working code
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // intializes the variables
    FILE *file_pointer;
    int character;
    char file_name[100];

    // gets the file name from the user
    printf("Enter file name:\n");
    scanf("%99s", file_name);

    // trys to open the file
    file_pointer = fopen(file_name, "r");
    // errors if file doesnt open
    if (file_pointer == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // prints out the character
    while ((character = fgetc(file_pointer)) != EOF)
    {
        printf("%c", character);
    }
    // closes the file
    fclose(file_pointer);
    return 0;
}
