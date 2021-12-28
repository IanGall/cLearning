#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Name :  <insert name here>
 *
 * Simple Wumpus game in 1D
*/

/* Add any #defines here */
/*Id's for things in our Cave*/
#define Empty 0
#define Wumpus 1
#define End 2
/*Number of rooms in our Cave*/
#define CaveSize 20
#define ArraySize (CaveSize + 2)
/*Directions I can face*/
#define Left 0
#define Right 1
#define FireRange 3

/* Add any function prototypes here */
void createWorld(int cave[]);

int *getEmptyRoom(int cave[]);

void displayWorld(int cave[], int *agent, int agentDir);

int differenceByDirection(int dir);

bool displayStatus(int cave[], int *pWumpus);

void fireByDirection(int direction, int *agentRoom);

int main() {
    /*Seed the random number generator*/
    srand(time(NULL));

    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    char command[20];
    int direction;

    createWorld(cave);
    agentRoom = getEmptyRoom(cave);
    agentDirection = rand() % 2;

    /*The game loop*/
    while (true) {
        if (displayStatus(cave, agentRoom)) {
            break;
        }
//        displayWorld(cave, agentRoom, agentDirection);
        /*Get the command*/
        printf("Command: ");
        setbuf(stdout, 0);
        scanf("%20s", command);
        if (strcmp(command, "q") == 0) {
            /*Exit, we are doing*/
            break;
        } else if (strcmp(command, "m") == 0) {
            /*Move command*/
            /*What way do we need to go? */
            direction = differenceByDirection(agentDirection);
            if (*(agentRoom + direction) != End) {
                agentRoom += direction;
            }
        } else if (strcmp(command, "t") == 0) {
            agentDirection = !agentDirection;
        } else if (strcmp(command, "f") == 0) {
            fireByDirection(agentDirection, agentRoom);
        } else {
            printf("I don't know what you are talking about\n");
        }
    }
}

void fireByDirection(int direction, int *agentRoom) {
    int delta = (direction == Left) ? -1 : 1;
    int *position;
    int i;
    for (i = 1; (i <= FireRange) && *(position = (agentRoom + delta * i)) != End; ++i) {
        if (*position == Wumpus) {
            *position = Empty;
            return;
        }
    }
}

void createWorld(int *cave) {
    int i;
    int *room;
    for (i = 0; i < ArraySize; ++i) {
        cave[i] = Empty;
    }
    cave[0] = End;
    cave[ArraySize - 1] = End;

    /*Get a random empty room and put the Wumpus in it*/
    room = getEmptyRoom(cave);
    *room = Wumpus;
}

int *getEmptyRoom(int *cave) {
    int room;
    do {
        room = rand() % ArraySize;
    } while (cave[room] != Empty);
    return &cave[room];
}

void displayWorld(int *cave, int *agent, int agentDir) {
    int *room;
    for (room = cave + 1; *room != End; ++room) {
        if (room == agent) {
            switch (agentDir) {
                case Left:
                    printf("<A  ");
                    break;
                case Right:
                    printf(" A> ");
                    break;
            }
            continue;
        }
        switch (*room) {
            case Wumpus:
                printf("-W- ");
                break;
            default:
                printf(" .  ");
                break;
        }
    }
    printf("\n");
}

int differenceByDirection(int dir) {
    return dir == Left ? -1 : 1;
}

bool displayStatus(int *cave, int *agent) {
    /*We will return true to indicate we are dead!*/
    int *pI;
    bool hasWumpus = false;
    for (pI = cave + 1; *pI != End; pI++) {
        if (*pI == Wumpus) {
            hasWumpus = true;
            break;
        }
    }
    if (!hasWumpus) {
        printf("Congratulations, the Wumpus is killed!");
        return true;
    }

    if (*agent == Wumpus) {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    if (*(agent - 1) == Wumpus || *(agent + 1) == Wumpus) {
        printf("I smell a Wumpus\n");
    }
    return false;
}
