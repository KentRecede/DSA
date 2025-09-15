#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"


void initStack(Stack *s){
    s->top = -1;
}

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

bool StackisEmpty(Stack *s){
    return s->top == -1;
}

bool StackisFull(Stack *s){
    return s->top == MAX - 1;
}

bool QueueisEmpty(Queue *q){
    return q->rear == -1;
}

bool QueueisFull(Queue *q){
    return ((q->rear + 1) % MAX == q->front);
}

bool push(Stack *s, studentInfo stud){
    if(StackisFull(s)){
        return false;
    }

    s->stackArr[++s->top] = stud;

    return true;
}

bool pop(Stack *s){
    if(StackisEmpty(s)){
        return false;
    }

    s->top--;

    return true;
}

studentInfo peek(Stack *s){
    return s->stackArr[s->top];
}

bool enqueue(Queue *q, studentInfo data){
    if((q->rear + 2) % MAX == q->front){
        q->rear = (q->rear + 1) % MAX;
        q->queueArr[q->rear] = data;
    }

    return true;
}

bool dequeue(Queue *q){
    if((q->rear + 1) % MAX == q->front){
        q->front = (q->front + 1) % MAX;
    }

    return true;
}

void displayStack(Stack s){

}

void displayQueue(Queue q){
    
}





