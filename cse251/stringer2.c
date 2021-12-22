#include <stdio.h>
#include <string.h>

void printLength(const char *word);
void reverse(char *str);

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
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    printLength(mySentence);
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
