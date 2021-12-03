/* This program is nothing more than a simple demonstration of the
 * putchar() function*/
#include <stdio.h>
#include <string.h>

int main(){
    int  i;
    char msg[] = "C is fun";
    for (i = 0; i < strlen(msg); ++i) {
        putchar(msg[i]); //Outputs a single character
    }
    putchar('\n'); //One line break after the loop is done.
}