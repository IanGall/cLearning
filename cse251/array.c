#include <stdio.h>

/**
 * IanQian
 * Program to experiment with arrays
 */

#define NumMovies 10

int main() {
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};

    double sum = 0;
    int i;
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                              "Just Go With It", "Gnomeo and Juliet", "Drive Angry",
                              "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                              "True Grit"};
    int highestGrossIndex = 0;
    double highestGross = 0;

    for (i = 0; i < NumMovies; ++i) {
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);

    for (i = 0; i < NumMovies; ++i) {
        printf("Movie %d %s: %.0f\n", i + 1, names[i], gross[i]);
    }

    for ( i = 0; i < NumMovies; ++i) {
        if (gross[i] > highestGross) {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }

    printf("The highest grossing film is: ")
}