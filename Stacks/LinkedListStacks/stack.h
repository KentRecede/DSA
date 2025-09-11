#ifndef STACK_H
#define STACK_H

typedef struct node{
    int data;
    struct node *next;
}*Node;

void initStack(Node *link);
bool isEmpty(Node *link);
bool isFull(Node *link);
bool push(Node *link, int data);
bool pop(Node *link);
int peek(Node *link);
void display(Node link);

#endif