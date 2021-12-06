#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
 * Simple lunar lander program
 * You landed with a velocity of -1.95, in 15s
 * The amount of fuel remaining is 85
 * */

int main() {
    printf("Lunar Lander - (c) 2012, by <IanQian>\n");

    double altitude = 100; /*Meters*/
    double velocity = 0; /*Meters per second*/
    double fuel = 100; /*Kilograms*/
    double power = 1.5; /*Acceleration per pound of fuel*/
    double g = -1.63; /*Moon gravity in m/s^2*/
    double burn; /*Amount of fuel to burn*/
    bool valid; /*Valid data entry flag*/
    int time = 0; /*Landing Time in s*/

    while (altitude > 0) {
        printf("Altitude: %.1f\n", altitude);
        printf("Velocity: %.1f\n", velocity);
        printf("You have %.1f kilograms of fuel\n", fuel);

        time++;

        do {
            printf("How much fuel would you like to burn: ");
            scanf("%lf", &burn);
            valid = false;

            if (burn < 0) {
                printf("You can't burn negative fuel\n");
            } else if (burn > fuel) {
                printf("You can't burn fuel you don't have\n");
            } else if (burn > 5) {
                printf("You can't burn more than 5 kilograms per second\n");
            } else {
                printf("Burning %.lf kilograms of fuel\n", burn);
                valid = true;
            }
        } while (!valid);

        velocity += (g + power * burn);
        altitude += velocity;
        fuel -= burn;

        printf("Altitude: %.2f\n", altitude);
        printf("Velocity: %.2f\n", velocity);
        printf("You have %.lf kilograms of fuel\n", fuel);
    }

    printf("You landed with a velocity of %.2f, in %ds\n", velocity, time);
    if (fabs(velocity) > 3) {
        printf("Your next of kin have been notified\n");
    }
    printf("The amount of fuel remaining is %.lf", fuel);
}