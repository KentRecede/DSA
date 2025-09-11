#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
bool push(Stack *s, int data);
bool pop(Stack *s);
int peek(Stack *s);
void display(Stack s);



#endif
