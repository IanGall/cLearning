#include <stdio.h>

/**
 * IanQian
 * Program to experiment with character arrays
 */

#define MaxWord 20

int main() {
    char c;
    char str[MaxWord + 1];
    int len = 0;
    int wordsCount = 0;
    double wordsLenSum = 0;
    int isLongWord = 0;

    puts("Enter text. Include a dot ('.') to end a sentence to exit:");
    do {
        c = getchar();
        if (c != ' ' && c != '.') {
            /*This is a character of a word*/
            if (len < MaxWord) {
                str[len] = c;
                len++;
            } else {
                str[len] = c;
                len++;
                isLongWord = 1;
                wordsLenSum += len;
                str[len] = 0;
                printf("%s", str);
                len = 0;
            }
        } else {
            if (len == 0) {
                if (isLongWord) {
                    isLongWord = 0;
                    printf("\n");
                }
                continue;
            }
            wordsLenSum += len;
            wordsCount++;

            /*The word is done*/
            str[len] = 0;
            printf("%s\n", str);
            len = 0;
        }
    } while (c != '.');

    printf("The average word length is %.2lf\n", wordsLenSum / wordsCount);
}