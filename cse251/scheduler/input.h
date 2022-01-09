#ifndef INPUT_H
#define INPUT_H

#include "scheduler.h"

#define __USE_XOPEN
#include <time.h>


void insertEvent(Event *events, int index);

time_t inputDate(char *prompt);

time_t inputTime(char *prompt, time_t date);


#endif