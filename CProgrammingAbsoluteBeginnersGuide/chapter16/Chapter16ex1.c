#include <stdio.h>

int main() {
    int  numTest;
    float stTest, avg, total = 0.0;

    //Asks for up to 25 tests
    for ( numTest = 0; numTest < 25; ++numTest) {
        //Get the test scores, and check if -1 was entered
        printf("\nWhat is the next students's test score? ");
        scanf(" %f", &stTest);
        if (stTest < 0.0) {
            break;
        }
        total += stTest;
    }

    avg = total / numTest;
    printf("\nThe average is %.1f%%.\n", avg);
}