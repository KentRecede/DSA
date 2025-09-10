/* **********************************************************************************
                             📋 Instructions
 1. Initialize a Flights structure with a dynamic array (use malloc).
 2. Implement createFlight() to input flight details from the user.
 3. Implement addFlight() to append a flight, resizing the array if count == max.
 4. Implement removeFlight() to delete a flight by ID and shift remaining elements.
 5. Implement showFlights() to display all flights.
 6. Implement displayFlightInfo() to show details of a single flight. 
 ************************************************************************************ */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "header.c"

int main() {
    Flights f;
    initFlight(&f);

    int choice;
    do {
        printf("\nFlight Management System\n");
        printf("1. Create and Add Flight\n");
        printf("2. Remove Flight by ID\n");
        printf("3. Show All Flights\n");
        printf("4. Display Flight Info by ID\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int id;
                char origin[50], destination[50];
                Time departure, arrival;

                printf("Enter Flight ID: ");
                scanf("%d", &id);
                printf("Enter Origin: ");
                scanf("%s", origin);
                printf("Enter Destination: ");
                scanf("%s", destination);
                printf("Enter Departure Time (HH MM): ");
                scanf("%d %d", &departure.hours, &departure.minutes);
                printf("Enter Arrival Time (HH MM): ");
                scanf("%d %d", &arrival.hours, &arrival.minutes);

                Flight newFlight = createFlight(id, origin, destination, departure, arrival);
                addFlight(&f, newFlight);
                printf("✅ Flight added successfully!\n");
                break;
            }

            case 2: {
                int id;
                printf("Enter Flight ID to remove: ");
                scanf("%d", &id);
                removeFlight(&f, id);
                break;
            }

            case 3:
                showFlights(f);
                break;

            case 4: {
                displayFlightInfo(f.flights[0]);
                break;
            }

            case 0:
                printf(" Exiting program. Safe travels!\n");
                break;

            default:
                printf(" Invalid choice. Please try again.\n");
        }

    } while(choice != 0);

    
    return 0;
}