#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Name :  <insert name here>
 *
 * Simple Wumpus game in 2D
*/

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
#define Pit 3

/* Number of rooms in our Cave in each dimension */
#define CaveSize 10
#define PitSize 10
#define FireRange 3
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Up 1
#define Right 2
#define Down 3

void createWorld(int cave[ArraySize][ArraySize]);

int *getEmptyRoom(int cave[ArraySize][ArraySize]);

void displayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir);

int differentByDirection(int dir);

bool displayStatus(int *pAgent, int *pWumpus);

void fireByDirection(int *pAgent, int direction);

bool isNearBy(const int *pAgent, int thing);

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    int *agentRoom;
    int agentDirection;
    char command[20];
    int cave[ArraySize][ArraySize];
    int *room;
    int d;

    createWorld(cave);
    room = getEmptyRoom(cave);
    *room = Wumpus;
    agentRoom = getEmptyRoom(cave);
    agentDirection = rand() % 4;
    for (int i = 0; i < PitSize; ++i) {
        *getEmptyRoom(cave) = Pit;
    }

    /* The game loop */
    while (true) {
        displayWorld(cave, agentRoom, agentDirection);
        if (displayStatus(agentRoom, room)) {
            break;
        }
        /* Get the command */
        printf("Command: ");
        setbuf(stdout, 0);
        scanf("%20s", command);
        if (strcmp(command, "q") == 0) {
            /* Exit, we are doing */
            break;
        } else if (strcmp(command, "m") == 0) {
            d = differentByDirection(agentDirection);
            if (*(agentRoom + d) != End) {
                agentRoom += d;
            }
        } else if (strcmp(command, "t") == 0) {
            agentDirection++;
            if (agentDirection > Down) {
                agentDirection = Left;
            }
        } else if (strcmp(command, "f") == 0) {
            fireByDirection(agentRoom, agentDirection);
        } else {
            printf("I don't know what you are talking about\n");
        }
    }
}

void fireByDirection(int *pAgent, int direction) {
    int delta = differentByDirection(direction);

    int i;
    int *pFire;
    for (i = 0; i <= FireRange && *(pFire = (pAgent + i * delta)) != End; ++i) {
        if (*pFire == Wumpus) {
            *pFire = Empty;
            break;
        }
    }
}

bool isNearBy(const int *pAgent, int thing) {
    return *(pAgent + 1) == thing || *(pAgent - 1) == thing ||
           *(pAgent - ArraySize) == thing || *(pAgent + ArraySize) == thing;
}

bool displayStatus(int *pAgent, int *pWumpus) {
    if (*pWumpus == Empty) {
        printf("The Wumpus has been killed\n");
        return true;
    }
    if (*pAgent == Pit) {
        printf("You fell into a pit\n");
        return true;
    }
    if (*pAgent == Wumpus) {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }

    if (isNearBy(pAgent, Pit)) {
        printf("I feel a draft\n");
    }

    if (isNearBy(pAgent, Wumpus)) {
        printf("I smell a Wumpus\n");
    }

    if (isNearBy(pAgent, End)) {
        printf("I'm against an End\n");
    }

    return false;
}

void createWorld(int (*cave)[12]) {
    int i;
    int j;
    for (i = 0; i < ArraySize; ++i) {
        for (j = 0; j < ArraySize; ++j) {
            if (i == 0 || j == 0 || i == ArraySize - 1 || j == ArraySize - 1) {
                cave[i][j] = End;
            } else {
                cave[i][j] = Empty;
            }
        }
    }
}

int *getEmptyRoom(int (*cave)[12]) {
    int row, col;
    int *room = NULL;
    do {
        row = rand() % ArraySize;
        col = rand() % ArraySize;

        room = &cave[row][col];
    } while (*room != Empty);
    return room;
}

void displayWorld(int (*cave)[12], int *agent, int agentDir) {
    int row, col;
    int *room;
    /*Loop over the rows of the cave*/
    for (row = 1; row <= CaveSize + 1; ++row) {
        /*This loop lets up print an up direction
         * above the agent or a v below the agent*/
        for (col = 1; col <= CaveSize; ++col) {
            if (&cave[row][col] == agent && agentDir == Up) {
                printf(" ^  ");
            } else if (&cave[row - 1][col] == agent && agentDir == Down) {
                printf(" v  ");
            } else {
                printf("    ");
            }
        }

        printf("\n");
        if (row > CaveSize)
            break;

        /*This loop prints the agent or the room contents*/
        for (col = 1; col <= CaveSize; ++col) {
            room = &cave[row][col];
            if (room == agent) {
                switch (agentDir) {
                    case Left:
                        printf("<A  ");
                        break;
                    case Right:
                        printf(" A> ");
                        break;
                    default:
                        printf(" A  ");
                        break;
                }
                continue;
            }
            switch (*room) {
                case Wumpus:
                    printf("-W- ");
                    break;
                case Pit:
                    printf(" o  ");
                    break;
                default:
                    printf(" .  ");
                    break;
            }
        }
        printf("\n");
    }
}

int differentByDirection(int dir) {
    switch (dir) {
        case Up:
            return -ArraySize;
        case Down:
            return ArraySize;
        case Left:
            return -1;
        case Right:
            return 1;
    }
    return 0;
}
