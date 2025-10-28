#ifndef HEADER_H
#define HEADER_H

#define MAX 10

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int arr[MAX];
    int top;
}Stack;


void initStack(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
bool push(Stack *s, int data);
bool pop(Stack *s);
int peek(Stack *);
void display(Stack s);


#endif