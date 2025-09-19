#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "header.h"

void initQueue(LLQueue *q){
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(LLQueue q){
    return q.front == NULL && q.rear == NULL;
}

bool isFull(LLQueue q){
    return false;
}

bool enqueue(LLQueue *q, int data){
    List temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(!temp){
        return false;
    }

    if(q->front == NULL){
        q->front = temp;
        q->rear = temp;
    }else {
        q->rear->next = temp;
        q->rear = temp;
    }

    return true;

}

bool dequeue(LLQueue *q){
    if(isEmpty(*q)){
        return false;
    }

    List temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);

    return true;
}

int top(LLQueue *q){
    return q->front->data; 
}

void display(LLQueue q){
    List temp = q.front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next; 
    }

    printf("\n");
}