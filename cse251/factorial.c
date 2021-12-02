#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* Simple program to experiment with looping*/

int main() {
    int f = 4;
    int fac = 1;

    while (f > 0) {
        fac *= f;
        f--;
    }

    printf("Factorial = %d\n", fac);
}