#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"

time_t inputDate(char *prompt) {
    char buffer[100];
    char *result;
    struct tm date;

    do {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while (result == NULL);

    /* Convert to time_t format */
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    return mktime(&date);
}

time_t inputTime(char *prompt, time_t date) {
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        result = strptime(buffer, "%I:%M%p", &time);

    } while (result == NULL);

    return mktime(&time);
}

void insertEvent(Event *events, int index) {
    Event *pEvent = events + index;
    printf("What is the event: ");
    scanf("%s", pEvent->name);
    fgetc(stdin);
    pEvent->date = inputDate("Event date: ");
    (pEvent->startTime) = inputTime("Start time: ", pEvent->date);
    (pEvent->endTime) = inputTime("End time: ", pEvent->date);

}

