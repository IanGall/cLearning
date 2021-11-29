#include <stdio.h>
#include <string.h>

int main() {
    int ctr, numMovies, rating, favRating, leastRating;
    char movieName[40], favorite[40], least[40];

    /* initialize the favRating to 0 so any movie with any rating of
     * 1 orhigher will replace it and the least Rating to 10 so any
     * movie rated 9 or lower will replace it*/
    favRating = 0;
    leastRating = 10;

    /* find out how many movies the user has seen and can rate
     * The loop will continue until they enter a number more than 0*/

    do {
        printf("How many movies have you seen this year?");
        scanf(" %d", &numMovies);

        /* If the user enters 0 or a negative number, the program
         * will remind them to enter a positive number and prompt
         * them again*/

        if (numMovies < 1) {
            printf("No movies! How can you rank them?\nTry again!\n\n");
        }
    } while (numMovies < 1);

    for (ctr = 1; ctr <= numMovies; ctr++) {
        //Get the name of the movie and the user's rating

        printf("\nWhat was the name of the movie?");
        printf("(1-word titles only!) ");
        scanf(" %s", movieName);
        printf("On a scale of 1 to 10, what would ");
        printf("you rate it? ");
        scanf(" %d", &rating);

        //Check whether it's their best-rated movie so far
        if (rating > favRating) {
            strcpy(favorite, movieName);
            favRating = rating;
        }

        //Check whether it's their worst-rated movie so far
        if (rating < leastRating) {
            strcpy(least, movieName);
            leastRating = rating;
        }
    }

    printf("\nYour Favorite Movie was %s.\n", favorite);
    printf("\nYour Least-favorite Movie was %s.\n", least);
}