#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scheduler.h"
#include "input.h"
#include "display.h"

void deleteEvents(Event *pEvents, int *pLength);


int main() {
    int nextEventI = 0;
    int eventLength = EvenLength;
    size_t size = sizeof(Event);
    Event *events = malloc((eventLength) * size);
//    size_t i = sizeof(events);
    int option;
    int flag = 1;

    do {
        printf("1 - Insert a new event\n"
               "2 - Display all events\n"
               "3 - Now?\n"
               "4 - Delete expired\n"
               "0 - Exit\n"
               "Please select an option: ");
        option = fgetc(stdin);
        fgetc(stdin);
        switch (option) {
            case '1':
                if (nextEventI == eventLength) {
                    events = realloc(events, (eventLength += EvenLength) * size);
                }
                insertEvent(events, nextEventI++);
                break;
            case '2':
                displayAllEvents(events, nextEventI);
                break;
            case '3':
                displayActiveEvents(events, nextEventI);
                break;
            case '4':
                deleteEvents(events, &nextEventI);
                break;
            case '0':
                flag = 0;
                break;
        }
    } while (flag);
}

void deleteEvents(Event *pEvents, int *pLength) {
    printf("Deleting: \n");
    for (int i = 0; i < *pLength; ++i) {
        time_t curTime = time(&curTime);
        if (curTime > (pEvents + i)->endTime) {
            displayEvents(pEvents + i);
            *(pEvents + i) = *(pEvents + *(pLength) - 1);
            (*pLength)--;
            i--;
        }
    }
}
