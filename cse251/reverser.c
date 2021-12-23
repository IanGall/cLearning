#include <stdio.h>
#include <string.h>

void reverse(char *str);

FILE *inFIle;
FILE *outFile;

/*
 * Name : <IanQian>
 * Program to experiment with files
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments\n");
        return 1;
    }

    printf("%s\n", argv[0]);
    printf("Copy from file: %s\n", argv[1]);
    printf("Copy to fileL %s\n", argv[2]);

    inFIle = fopen(argv[1], "r");
    outFile = fopen(argv[2], "w");
    char line[120];

    if (inFIle == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    if (outFile == NULL) {
        printf("Unable to open file %s\n", argv[2]);
        return 1;
    }

    while (!feof(inFIle)) {
        /*Read a line of text from the file*/
        fgets(line, sizeof(line), inFIle);
        reverse(line);

        /*Remove the newline at the end of the line*/
        if (strlen(line) > 0) {
            line[strlen(line) - 1] = '\0';
        }
        fprintf(outFile, "%s\n", line);
    }

    fclose(inFIle);
    fclose(outFile);
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
