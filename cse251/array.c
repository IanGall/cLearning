#include <stdio.h>

/**
 * IanQian
 * Program to experiment with arrays
 */

#define NumMovies 10
#define MaxGrosses 5

void selectSort(int size, double pDouble[10], char *pString[10]);

void swap(double *pDouble, double *pDouble1);

void swapChars(char **pString, char **pString1);

void isGreaterThan(const double *gross, int i, char *const *names, int *maxGrossIndex, double max);

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
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};

    for (i = 0; i < NumMovies; ++i) {
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);

    for (i = 0; i < MaxGrosses; ++i) {
        selectSort(NumMovies, gross, names);
    }

    for (i = 0; i < NumMovies; ++i) {
        printf("Movie %d %s: %.0f\n", i + 1, names[i], gross[i]);
    }

    for (i = 0; i < NumMovies; ++i) {
        if (gross[i] > highestGross) {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }

    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

    int maxGrossIndex = 1;
    double max;
    max = maxGross[0];
    if (gross[0] >= max) {
        printf("No film made less than %.0f\n", max);
    }
    for (i = 1; i < NumMovies; ++i) {
        max = maxGross[maxGrossIndex];
        isGreaterThan(gross, i, names, &maxGrossIndex, max);
    }
    printf("The highest gross less than %.0f is %s at %d\n", maxGross[maxGrossIndex], names[NumMovies - 1],
           NumMovies - 1);

}

void isGreaterThan(const double *gross, int i, char *const *names, int *maxGrossIndex, double max) {
    if (gross[i] >= max) {
        printf("The highest gross less than %.0f is %s at %d\n", max, names[i - 1], i - 1);
        (*maxGrossIndex)++;
    }
}

void selectSort(int size, double pDouble[10], char *pString[10]) {
    int outer;
    int inner;
    int minI = 0;
    for (outer = 0; outer < size - 1; ++outer) {
        for (inner = outer; inner < size; ++inner) {
            if (pDouble[inner] < pDouble[minI]) {
                minI = inner;
            }
        }
        if (minI != outer) {
            swap(&pDouble[outer], &pDouble[minI]);
            swapChars(&pString[minI], &pString[outer]);
        }
    }
}

void swapChars(char **pString, char **pString1) {
    char *temp = *pString;
    *pString = *pString1;
    *pString1 = temp;
}

void swap(double *pDouble, double *pDouble1) {
    double temp = *pDouble;
    *pDouble = *pDouble1;
    *pDouble1 = temp;
}
