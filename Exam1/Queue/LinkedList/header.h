#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}*List;

typedef struct{
    List front;
    List rear;
}LLQueue;


void initQueue(LLQueue *q);
bool isEmpty(LLQueue q);
bool isFull(LLQueue q);
bool enqueue(LLQueue *q, int data);
bool dequeue(LLQueue *q);
int top(LLQueue *q);
void display(LLQueue q);



#endif