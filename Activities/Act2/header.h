#ifndef HEADER_H
#define HEADER_H


#define STACK_SIZE 100


typedef struct{
    int hours;
    int minutes;
}Time;

typedef struct {
    int id;
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
} Flight;

typedef struct {
    Flight stack[STACK_SIZE];
    int top;
} FlightStack;

void initStack(FlightStack *s);
int isStackEmpty(FlightStack *s);
int isStackFull(FlightStack *s);
void pushFlight(FlightStack *s, Flight f);
Flight popFlight(FlightStack *s);
Flight peekFlight(FlightStack s);



#endif