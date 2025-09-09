#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int arr[MAX];
    int front,rear;
}Queue;

void initQueue(Queue *q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
bool enqueue(Queue *q, int data);
bool dequeue(Queue *q);
int front(Queue *q);
void display(Queue *q);


#endif