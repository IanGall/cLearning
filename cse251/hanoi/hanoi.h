#ifndef HANOI_H
#define HANOI_H

#define NumPins 3
#define NumDisks 6
#define MaxDiskSize 13

void DisplayDisk(int p);


/*
 * Name :  <insert name here>
 *
 * Simple Towers of Hanoi game. You can solve it yourself or
 * ask the game to solve it for you.
 */

void DisplayTower(int tower[NumPins][NumDisks]);

void Reset(int tower[NumPins][NumDisks]);

int InputPin(char *msg, int fm, int to);

bool CheckDone(int tower[NumPins][NumDisks]);

void MoveDisk(int tower[NumPins][NumDisks], int fm, int to);

#endif