/* The program demonstrates passing an array to a function.*/
#include <stdio.h>
#include <string.h>

void change(char name[15]);

main(){
    char name[15] = "Michael Hatton";
    change(name);
    printf("Back in main(), the name is now %s.\n", name);
}

/**
 * Change the string stored at the address pointed to by name
 * @param name
 */
void change(char name[15]) {
    strcpy(name, "XXXXXXXXXXX");
    return;
}
