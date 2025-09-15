#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct{
    char fname[20];
    char lname[20];
    char MI;
}Name;

typedef struct{
    Name studentName;
    int year;
    char program[4];
    char sex;   //m or f
}studentInfo;

typedef struct{
    studentInfo stackArr[MAX];
    int top;
}Stack;

typedef struct{
    studentInfo queueArr[MAX];
    int front; 
    int rear;
}Queue;


void initStack(Stack *s);
void initQueue(Queue *q);
bool StackisEmpty(Stack *s);
bool StackisFull(Stack *s);
bool QueueisEmpty(Queue *q);
bool QueueisFull(Queue *q);
bool push(Stack *s, studentInfo data);
bool pop(Stack *s);
int peek(Stack *s);
bool enqueue(Queue *q);
bool dequeue(Queue *q);
void displayStack(Stack s);
void displayQueue(Stack q);



#endif