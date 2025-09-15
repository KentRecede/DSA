#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int arr[MAX];
    int count;
}Arr;

void initArr(Arr a);
bool insertFront(Arr *a);



#endif