/*The program is a simple demonstration of the difference between
 * global variables and local variables.*/
#include <stdio.h>

int g1 = 10;

void prAgain();

int main() {
    float l1;
    l1 = 9.0f;

    printf("%d %.2f\n", g1, l1); //prints the 1st global and first local variable

    prAgain(); //calls our first function
}

float g2 = 19.0f;

void prAgain() {
    int l2 = 5;

    //Can't print l1--it is local to main
    printf("%d %.2f %d\n", l2, g2, g1);
}
