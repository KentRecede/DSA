#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dictionary.h"

#define MAX 8

void initSet(Set *x){
    *x = 0;
}

void insert(Set *s, int elem){
    if(elem >= 0 && elem < MAX){
        (*s) |= (1 << elem);
    }
}

bool member(Set *s, int elem){
    return ((*s) & (1 << elem)) ? true : false;
}

Set *Union(Set x, Set y){
    Set *z = malloc(sizeof(Set));
    (*z) = x | y;
    return z;
}

Set *Intersection(Set x, Set y){
    Set *z = malloc(sizeof(Set));
    (*z) = x & y;
    return z;
}

Set *Difference(Set x, Set y){
    Set *z = malloc(sizeof(Set));
    (*z) = x & ~y;
    return z;
}

Set *Compliment(Set x) {
    Set *z = malloc(sizeof(Set));
    *z = ~x & ((1 << MAX) - 1);
    return z;
}


void display(Set x, char *name){
    for(int i = MAX - 1; i >= 0; i--){
        if(x & (1 << i)){
            printf("%d ", i);
        }
    }

    printf("\n");
}

void displayBits(Set x, char *name){
    for(int i = MAX - 1; i >= 0; i--){
        if(x & (1 << i)){
            printf("1");
        }else{
            printf("0");
        }
    }

    printf("\n");
}