#include <stdio.h>

//#include "input.h"
#include "display.h"


void displayActiveEvents(Event *pEvents, int length) {
    printf("Currently active events: \n");
    bool useActiveFlag = true;
    displayEventsByActiveFlag(pEvents, length, useActiveFlag);
}

void displayEventsByActiveFlag(Event *pEvents, int length, bool useActiveFlag) {
    int i;
    for (i = 0; i < length; ++i) {
        Event *pEvent = pEvents + i;
        time_t curTime = time(&curTime);
        if (useActiveFlag ? curTime <= pEvent->startTime || curTime > pEvent->endTime : false) {
            continue;
        }
        displayEvents(pEvent);
    }
}

void displayEvents(const Event *pEvent) {
    printDate(pEvent->date);
    printTime(pEvent->startTime);
    printTime(pEvent->endTime);
    printf(" %s\n", pEvent->name);
}

void displayAllEvents(Event *pEvents, int length) {
    printf("Schedule: \n");
    displayEventsByActiveFlag(pEvents, length, false);
}

void printTime(time_t time) {
    struct tm tm = *localtime(&time);
    bool isPM = tm.tm_hour >= 12;
    printf(" %d:%02d%s", isPM ? tm.tm_hour - 12 : tm.tm_hour, tm.tm_min, isPM ? "PM" : "AM");

}

void printDate(time_t date) {
    struct tm tm = *localtime(&date);
    printf(" %d/%d/%d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
}
