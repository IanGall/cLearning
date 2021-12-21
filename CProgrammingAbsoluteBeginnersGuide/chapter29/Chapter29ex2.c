/*The program opens the file created in the first program of
 * the chapter and changes one of the letters toan *. It then prints the new
 * list with the altered list of letters.*/
#include <stdio.h>
#include <stdlib.h>

#define  filename  "D:\\qianD\\c\\c-projects\\CProgrammingAbsoluteBeginnersGuide\\chapter29\\letters.txt"
FILE *fptr;

int main() {
    char letter;
    int i;

    fptr = fopen(filename, "r+");
    if (fptr == 0) {
        printf("There was an error while opening the file.\n");
        exit(1);
    }

    printf("Which # letter would you like to change (1-26)? ");
    scanf(" %d", &i);

    //Seeks that position from the beginning of the file
    fseek(fptr, (i - 1), SEEK_SET); //Subtract 1 from the position because array starts at 0

    //Write an * over the letter in that position
    fputc('*', fptr);

    //Now jump back to the beginning of the array  and print it out
    fseek(fptr, 0, SEEK_SET);
    printf("Here is the file now: \n");
    for ( i = 0; i < 26; ++i) {
        letter = fgetc(fptr);
        printf("The next letter is %c.\n", letter);
    }

    fclose(fptr);
}