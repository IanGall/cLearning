// Example program #3 from Chapter 28 of Absolute Beginner's Guide
// to C, 3rd Edition
// File Chapter28ex3.c
/* The program opens the existing book info file from the first example of chapter 28,
 * and adds a line to the end. */
#include <stdio.h>
#include <stdlib.h>

FILE *fptr;

main() {
    fptr = fopen("C:\\IanQian\\c\\projects\\cLearning\\CProgrammingAbsoluteBeginnersGuide\\chapter28\\BookInfo.txt",
                 "a");
    if (fptr == 0) {
        printf("Error opening the file! Sorry!\n");
        exit(1);
    }
// Adds the line at the end
    fprintf(fptr, "\nMore books to come!\n");
    fclose(fptr); // Always close your files return(0);
}