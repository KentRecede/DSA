#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"


void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q){
    return (q->rear == -1);
}

bool isFull(Queue *q){
    return ((q->rear + 1) % MAX) == q->front && !isEmpty(q);
}

bool enqueue(Queue *q, int data){
    if(isFull(q)){
        return false;
    }

    if(isEmpty(q)){
        q->rear = q->front;
    }else{
        q->rear = (q->rear + 1) % MAX;
    }

    q->arr[q->rear] = data;

    return true;

}

bool dequeue(Queue *q){
    if(q->front == q->rear){
        q->front = 0;
        q->rear = -1;
    }else{
        q->front == (q->front + 1) % MAX;
    }

    return true;
}

int front(Queue *q){
    return q->arr[q->front];
}

void display(Queue q){
    if(isEmpty(&q)){
        printf("No bullets!! Go reload");
        return;
    }

    int i = q.front;

    while(true){
        printf("%d ", q.arr[i]);
        if(i == q.rear) break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}