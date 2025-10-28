#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct{
    int arr[MAX];
    int front, rear;
}Queue;

void initQueue(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
bool enqueue(Queue *q, int data);
bool dequeue(Queue *q);
int peek(Queue q);
void display(Queue q);

#endif