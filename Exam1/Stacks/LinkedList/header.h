#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}*Stack;

void initStack(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
bool push(Stack *s, int data);
bool pop(Stack *s);
int peek(Stack s);
void display(Stack s);


#endif