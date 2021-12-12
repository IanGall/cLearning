#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InputQuadraticEquation(double *a, double *b, double *c);

void QuadraticEquation(double a, double b, double c, double *z1r, double *z1i, double *z2r, double *z2i);

int main() {
    /*Values for the quadratic formula*/
    double a, b, c;
    double z1r, z1i; /*First zero*/
    double z2r, z2i; /*Second zero*/

    InputQuadraticEquation(&a, &b, &c);

    /**
     * This code computes the quadratic equation
     * for both real and complex zeros
     */

    QuadraticEquation(a, b, c, &z1r, &z1i, &z2r, &z2i);

    /*Display the results*/
    printf("Zero 1: %f + %fj\n", z1r, z1i);
    printf("Zero 2: %f + %fj\n", z2r, z2i);
}

void QuadraticEquation(double a, double b, double c, double *z1r, double *z1i, double *z2r,
                       double *z2i) {
    /*Compute the discriminant*/
    double discriminant;
    discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        /*If the discriminant is greater than or
         * equal to zero, the zeros are real*/
        (*z1r) = (-b + sqrt(discriminant)) / (2 * a);
        (*z2r) = (-b - sqrt(discriminant)) / (2 * a);
        (*z1i) = 0;
        (*z2i) = 0;
    } else {
        /*If the discriminant is less than zero
         * the zeros are complex*/
        (*z1r) = -b / (2 * a);
        (*z2r) = (*z1r);
        (*z1i) = sqrt(-discriminant) / (2 * a);
        (*z2i) = -sqrt(-discriminant) / (2 * a);
    }
}

void InputQuadraticEquation(double *a, double *b, double *c) {
    printf("Input a: ");
    scanf("%lf", a);
    printf("Input b: ");
    scanf("%lf", b);
    printf("Input c: ");
    scanf("%lf", c);
}