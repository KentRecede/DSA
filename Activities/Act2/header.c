#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void initStack(FlightStack *s){
    s->top = -1;
}

int isStackEmpty(FlightStack *s){
    return s->top == -1;
}

int isStackFull(FlightStack *s){
    return s->top == STACK_SIZE;
}

void pushFlight(FlightStack *s, Flight f){
    if(isStackFull(s)){
        return;
    }

    s->stack[s->top] = f;
    ++(s->top);
}

Flight popFlight(FlightStack *s){

    Flight popped = s->stack[s->top];
    s->top--;

    return popped;
}

Flight peekFlight(FlightStack s){
    Flight peek = s.stack[s.top];

    return peek;
}

void displayFlight(FlightStack s) {
    if (s.top < 0) {
        printf("Flight stack is empty.\n");
        return;
    }

    printf("Flights in stack:\n");
    for (int i = s.top; i >= 0; i--) {
        printf("Flight #%d\n", i + 1);
        printf("  Flight ID: %d\n", s.stack[i].id);
        printf("  Origin: %s\n", s.stack[i].origin);
        printf("  Destination: %s\n", s.stack[i].destination);
        printf("  Departure Time: %s\n", s.stack[i].departure_time);
        printf("------------------------\n");
    }
}