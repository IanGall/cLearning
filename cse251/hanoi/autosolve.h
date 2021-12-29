
#ifndef AUTOSOLVE_H
#define AUTOSOLVE_H

/*
 * Automatically solve the Towers of Hanoi problem.
 * This resets the tower to the initial state, then
 * solves it one step at a time.
 */

void Autosolve(int tower[NumPins][NumDisks]);

void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to);

#endif