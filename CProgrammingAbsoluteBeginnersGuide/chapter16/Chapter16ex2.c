#include <stdio.h>

int main() {
    int i;

    //Loops through the numbers 1 through 10
    for (i = 1; i <= 10; ++i) {
        if ((i % 2) == 1) { //Odd numbers have a remainder of 1
            printf("I'm rather odd...\n");
            //Will jump to the next iteration of the loop
            continue;
        }
        printf("Even up!\n");
    }
}