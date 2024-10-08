
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 @brief prints the name of the parameter
 @param name the name of the person to be printed
*/
void printName(const char *name){
    printf("Name is %s",name);
}

int main(void){
    char *name = malloc(32);
    strcpy(name,"Bob");
    printName(name);    

    free(name);
    return 0;
}
