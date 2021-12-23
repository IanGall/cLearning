#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printLength(const char *word);
void reverse(char *str);
int numberOfSpaces(char *string);
int numberOfAppearances(char *string,char ch){
    if (!isalpha(ch)) {
        return 0;
    }

    ch = tolower(ch);

    int i = 0;
    int numCh = 0;
    while (string[i] != '\0') {
        if (tolower(string[i]) == ch) {
            numCh++;
        }
        i++;
    }
    return numCh;
}

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
    char mySentence[80];
    int len;

//    for (i = 0; word[i] != '\0'; ++i) {
//        printf("Location %d: %c\n", i, word[i]);
//    }

    printf("Enter a sentence: ");
    setbuf(stdout, 0);
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    printLength(mySentence);

    printf("The number of spaces is: %d\n", numberOfSpaces(mySentence));
    printf("The number of appearances is: %d\n", numberOfAppearances(mySentence,'i'));

    reverse(mySentence);
    printf("%s\n", mySentence);
}

void printLength(const char *word) {
    printf("The string %s is %d characters long\n", word, strlen(word));
}

void reverse(char *str) {
    int front = 0;
    int back = strlen(str) - 1;
    char t; /*A temporary place to put character*/

    while (front < back) {
        t = str[front];
        str[front] = str[back];
        str[back] = t;
        front++;
        back--;
    }
}

int numberOfSpaces(char *string) {
    int i = 0;
    int numSpaces = 0;
    while (string[i] != '\0') {
        if (string[i] == ' ') {
            numSpaces++;
        }
        i++;
    }
    return numSpaces;
}
