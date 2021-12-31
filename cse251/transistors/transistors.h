#ifndef TRANSISTORS_H
#define TRANSISTORS_H

/*Types*/
#define NPN 1
#define PNP 2

/*Class*/
#define TO18 1
#define TO92A 2
#define TO92C 3
#define TO92O 4
#define TO39 5

struct Transistor{
    char number[10];
    int type; /*NPN, PNP, etc.*/
    int caseStyle; /*TO18, etc.*/
    double pmax; /*Maximum power dissipation watts*/
    double icmax; /*Maximum collector current amps*/
};

void displayTransistor(struct Transistor tran);

struct Transistor inputTransistor();

void inputString(char *str, int max);

double inputPositiveValue(char *prompt);

int inputTransistorType(char *prompt);
#endif
