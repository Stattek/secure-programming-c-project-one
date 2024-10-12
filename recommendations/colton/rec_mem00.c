
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
    ///copies the string Bob to the name variable
    strcpy(name,"Bob");
    ///calls the print name function
    printName(name);    
    ///frees the name variable from the heap
    free(name);
    return 0;
}
