#ifndef DISPLAY
#define DISPLAY

#define __USE_XOPEN
#include <time.h>

#include <stdbool.h>

#include "scheduler.h"

void displayAllEvents(Event *pEvents, int length);

void printDate(time_t date);

void printTime(time_t time);

void displayActiveEvents(Event *pEvents, int length);

void displayEventsByActiveFlag(Event *pEvents, int length, bool useActiveFlag);

void displayEvents(const Event *pEvent);


#endif