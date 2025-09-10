/*📋 Instructions
1. Initialize the queue with front = rear = NULL.
2. Implement enqueueFlight() to add a flight to the rear.
3. Implement dequeueFlight() to remove a flight from the front.
4. Implement peekQueue() to view the next flight to board.
5. Simulate a boarding queue: enqueue flights in order and dequeue them as they board.
*/

#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "header.c"

int main() {
    FlightQueue q;
    initQueue(&q);

    // Create flights
    Flight f1 = {1, "Manila", "Tokyo", {8,30}, {11,15}};
    Flight f2 = {2, "Cebu", "Singapore", {10,15}, {13,45}};
    Flight f3 = {3, "Davao", "Bangkok", {12,45}, {15,30}};

    // Enqueue flights
    printf("Enqueuing Flight 1...\n");
    enqueueFlight(&q, f1);
    display(q);

    printf("\nEnqueuing Flight 2...\n");
    enqueueFlight(&q, f2);
    display(q);

    printf("\nEnqueuing Flight 3...\n");
    enqueueFlight(&q, f3);
    display(q);

    // Peek at the next flight to board
    Flight next = peekQueue(q);
    printf("\nNext to board: Flight %d (%s -> %s)\n",
           next.id, next.origin, next.destination);

    // Dequeue flights as they board
    printf("\nBoarding flights...\n");
    while (!isQueueEmpty(&q)) {
        Flight boarded = dequeueFlight(&q);
        printf("Boarded Flight %d (%s -> %s)\n",
               boarded.id, boarded.origin, boarded.destination);
        display(q);
    }

    return 0;
}
