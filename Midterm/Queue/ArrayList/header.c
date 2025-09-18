#include <stdio.h>
#include <stdbool.h>

#include "header.h"

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

bool isFull(Queue *q){
    return (q->rear + 2) % MAX == q->front;
}

bool isEmpty(Queue *q){
    return (q->rear + 1) % MAX == q->front;
}

bool enqueue(Queue *q, int data){
    if(isFull(q)){
        return false;
    }

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;

    return true;
}

bool dequeue(Queue *q){
    if(isEmpty(q)){
        return false;
    }

    q->front = (q->front + 1) % MAX;

    return true;
}

int peek(Queue q){
    return q.arr[q.front];
}

void display(Queue q){
    
    
    while(!isEmpty(&q)){
        int front = peek(q);
        printf("%d ", front);
        dequeue(&q);
    }

    printf("\n");
}

