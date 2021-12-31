/* The program again looks to fill three book structures with info, but it uses a pointer array this time. */
//First include the file with the structure definition 
#include "bookinfo.h"
#include <stdio.h>
#include <stdlib.h>

static const int size = 1;

main() {
    int ctr;
    struct bookInfo *books[size]; // Array of three structure variables
// Get the information about each book from the user
    for (ctr = 0; ctr < size; ctr++) {
        books[ctr] = (struct bookInfo *) malloc(sizeof(struct bookInfo));
        printf("What is the name of the book #%d?\n", (ctr + 1));
        gets(books[ctr]->title);
        puts("Who is the author? ");
        gets(books[ctr]->author);
        puts("How much did the book cost? ");
        scanf(" $%f", &books[ctr]->price);
        puts("How many pages in the book? ");
        scanf(" %d", &books[ctr]->pages);
        getchar(); //Clears newline input to keep things clean for // next round
    } // Print a header line and then loop through and print the info
    printf("\n\nHere is the collection of books: \n");
    for (ctr = 0; ctr < size; ctr++) {
        printf("#%d: %s by %s", (ctr + 1), books[ctr]->title, books[ctr]->author);
        printf("\nIt is %d pages and costs $%.2f", books[ctr]->pages, books[ctr]->price);
        printf("\n\n");
    }
    return (0);
}