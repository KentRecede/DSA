#include <stdio.h>
#include <stdlib.h>

#include "header.h"


void initQueue(FlightQueue *q){
    q->front = q->rear = NULL;
}

int isQueueEmpty(FlightQueue *q){
    return q->front == NULL;
}

void enqueueFlight(FlightQueue *q, Flight f){
    Node *temp = malloc(sizeof(struct Node));
    temp->data = f;
    temp->next = NULL;

    if(isQueueEmpty(q)){
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

Flight dequeueFlight(FlightQueue *q){
    
    Node *temp = q->front;
    Flight data = temp->data;
    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL;
    free(temp);

    return data;
}

Flight peekQueue(FlightQueue q){
    return q.front->data;
}

void display(FlightQueue q) {
    if (isQueueEmpty(&q)) {
        printf("Flight queue is empty.\n");
        return;
    }

    printf("Flights in queue:\n");
    Node *curr = q.front;
    while (curr != NULL) {
        Flight f = curr->data;
        printf("  Flight ID: %d\n", f.id);
        printf("  Origin: %s\n", f.origin);
        printf("  Destination: %s\n", f.destination);
        printf("  Departure Time: %02d:%02d\n", f.departure_time.hours, f.departure_time.minutes);
        printf("  Arrival Time:   %02d:%02d\n", f.arrival_time.hours, f.arrival_time.minutes);
        printf("-----------------------------\n");
        curr = curr->next;
    }
}
