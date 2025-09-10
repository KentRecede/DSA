#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

void initFlight(Flights *flight){
    flight->flights = malloc(sizeof(flight));
    flight->count = 0;
    flight->max = 0;

}

Flight createFlight(int id, char origin[], char destination[], Time departure_time, Time arraival_time){
    Flight flight;

    flight.id = id;
    strcpy(flight.origin, origin);
    strcpy(flight.destination, destination);
    flight.arrival_time = arraival_time;
    flight.departure_time = departure_time;
    
    return flight;
}

void addFlight(Flights *flight_list, Flight f){
    if(flight_list->count == flight_list->max){
        flight_list->max *= 2;
        flight_list->flights = realloc(flight_list->flights, sizeof(Flight) * flight_list->max);
    }

    for(int i = flight_list->count; i > 0; i--){
        flight_list->flights[i] = flight_list->flights[i - 1];
    }

    flight_list->flights[0] = f;
    flight_list->count++;
}


Flight removeFlight(Flights *flight_list, int flightid){
    if(flightid < flight_list->count){
        for(int i = flightid; i < flight_list->count; i++){
            flight_list->flights[i] = flight_list->flights[i + 1];
        }

        flight_list->count--;
    }
}

void showFlights(Flights flight_list){
    for(int i = 0; i < flight_list.count; i++){
        printf("ID: %d | Origin: %s | Destination: %s", flight_list.flights[i].id,
                                                        flight_list.flights[i].origin,
                                                        flight_list.flights[i].destination);
    }
}

void displayFlightInfo(Flight f) {
    printf("\n🛫 Flight Information\n");
    printf("ID: %d\n", f.id);
    printf("Origin: %s\n", f.origin);
    printf("Destination: %s\n", f.destination);
    printf("Departure Time: ");
    displaytime(f.departure_time);
    printf("\nArrival Time: ");
    displaytime(f.arrival_time);
    printf("\n");
}

Time createTime(int h, int m){
    Time t;

    t.hours = h;
    t.minutes = m;
    
    return t;
}

void displaytime(Time t){
    printf("%d:%d", t.hours, t.minutes);
}

