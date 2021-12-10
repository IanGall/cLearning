#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printCard(int suit, int card);

/**
* Program to draw playing cards
*/

int main() {
    int suit;
    int card;
    int order[] = {0, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    /*This seeds the random number
     * generator with the current time*/
    srand(time(NULL));

    /*Create a random card and suit
     * This will compute a random number from 0 to 3*/
    suit = rand() % 4;

    /*This will compute a random number from 1 to 13*/
    card = rand() % 13 + 1;

    int suit2 = rand() % 4;
    int card2 = rand() % 13 + 1;

    printCard(suit, card);
    printCard(suit2, card2);

    if (card == card2) {
        if (suit == suit2) {
            printf("There is a tie");
        } else {
            printf(suit < suit2 ? "Player 1 wins" : "Player 2 wins");
        }
    } else {
        printf(order[card] > order[card2] ? "Player 1 wins" : "Player 2 wins");
    }
}

void printCard(int suit, int card) {
    switch (card) {
        case 1:
            printf("Ace");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            printf("%d", card);
            break;
    }

    printf(" of ");

    switch (suit) {
        case 0:
            printf("Hearts");
            break;
        case 1:
            printf("Diamonds");
            break;
        case 2:
            printf("Spades");
            break;
        case 3:
            printf("Clubs");
            break;
    }
    printf("\n");
}
