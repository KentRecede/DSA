/*📋 Instructions
1. Initialize the stack with top = -1.
2. Implement pushFlight() to add a flight to the stack.
3. Implement popFlight() to remove the most recent flight.
4. Implement peekFlight() to view the top flight without removing it.
5. Simulate a flight history tracker: every time a flight is added or removed, push it to the stack.
*/


#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "header.c"

int main() {
    FlightStack flightStack;
    initStack(&flightStack);

    
    Flight f1 = {001, "Manila", "Tokyo", {8, 30}};
    Flight f2 = {002, "Cebu", "Singapore", {10, 15}};
    Flight f3 = {003, "Davao", "Bangkok", {12, 45}};


    pushFlight(&flightStack, f1);
    pushFlight(&flightStack, f2);
    pushFlight(&flightStack, f3);

    
    printf("Initial flight stack:\n");
    displayFlight(flightStack);

    Flight popped = popFlight(&flightStack);
    printf("\nPopped flight:\n");
    printf("  Flight ID: %d\n", popped.id);
    printf("  Origin: %s\n", popped.origin);
    printf("  Destination: %s\n", popped.destination);
    printf("  Departure Time: %02d:%02d\n", popped.departure_time.hours, popped.departure_time.minutes);

    printf("\nUpdated flight stack:\n");
    displayFlight(flightStack);

    return 0;
}
