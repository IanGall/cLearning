#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "transistors.h"

/*
 * Name :  < insert name here >
 * Description : Simple transistor description example program
*/

int main() {
    struct Transistor t1;

    t1 = inputTransistor();

    printf("transistors!\n");
    displayTransistor(t1);
}