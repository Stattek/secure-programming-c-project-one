/*
Description: Recommendation MEM00-C states that you should allocate and free memory in the same module and at the same abstraction level. This means that 
    if you allocate memory for an object you should free that object in the same scope and area of code that way you do not double free the memory by accident.

Why it is important: This recommendation is important to follow because if it is not followed it can lead to double freeing memory which leads to a vulnerability that 
    attackers can exploit to allow them to execute their own code on the system with the permissions of the process that the vulnerability is in. Not following
    this recommendation can also lead to errors that can cause resource depletion and denial of service attacks because of double freeing memory.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printName(const char *name){
    printf("Name is %s",name);
}

int main(){
    char *name = malloc(32);
    strcpy(name,"Bob");
    printName(name);    

    free(name);
    return 0;
}
