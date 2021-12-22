#include <stdio.h>
#include <string.h>

void printLength(const char *word);

int StringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/*
 * Name : <IanQian>
 * Program to experiment with strings
 */

int main() {
    char word[] = "chudge";
    char myWord[80];
    char mySentence[80];
    char c[1];
    int i;
    int len;

//    for (i = 0; word[i] != '\0'; ++i) {
//        printf("Location %d: %c\n", i, word[i]);
//    }
    printf("Enter a word: ");
    scanf("%79s", myWord);
    myWord[79] = '\0';
    printf("The entered word is: %s\n", myWord);

    gets(c);

    printf("Enter a sentence: ");
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    printLength(word);
    printLength(myWord);
}

void printLength(const char *word) {
    printf("The string %s is %d characters long\n", word, strlen(word));
}
