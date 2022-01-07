#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxSize  20

typedef struct event {
    char *name;
    char *date;
    char *startTime;
    char *endTime;
} Event;

void insertEvent(Event *events, int index);

void insertEvent(Event *events, int index) {
    printf("What is the event: ");
    fgets((events + index)->name, maxSize, stdin);
    printf("Event date: ");
    fgets((events + index)->date, maxSize, stdin);
}


int main() {
    int eventIndex = 0;
    Event *events = malloc((eventIndex + 1) * sizeof(Event));

    printf("1 - Insert a new event\n"
           "2 - Display all events\n"
           "3 - Now?\n"
           "4 - Delete expired\n"
           "0 - Exit\n"
           "Please select an option: ");
    int option = fgetc(stdin);
    fgetc(stdin);
    if (option == '1') {
        insertEvent(events, eventIndex);
    }
}