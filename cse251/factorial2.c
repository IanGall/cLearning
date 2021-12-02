#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/* Simple program to experiment with looping*/

int main() {
    int f = 4, fac;


    while (true) {
        printf("Number to compute the factrial of : ");
        scanf(" %d", &f);

        if (f == 0) {
            f = 1;
        } else if (f < 0) {
            exit(1);
        }

        fac = 1;
        while (f > 0) {
            fac *= f;
            f--;
        }
        printf("Factorial = %d\n", fac);
    }

}