#ifndef SCHEDULER_H
#define SCHEDULER_H


#define EvenLength  1
#define maxSize  20

typedef struct event {
    char name[maxSize];
    time_t date;
    time_t startTime;
    time_t endTime;
} Event;


#endif