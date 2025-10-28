#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "header.h"

void initStack(Stack *s){
    *s = NULL;
}

bool isEmpty(Stack *s){
    return *s == NULL;
}

bool isFull(Stack *s){
    return false;
}

bool push(Stack *s, int data){
    Stack temp = malloc(sizeof(struct node));

    if(!temp){
        return false;
    }

    temp->data = data;
    temp->next = *s;
    *s = temp;

    return true;
}

bool pop(Stack *s){
    Stack temp = *s;

    if(isEmpty(s)){
        return false;
    }

    *s = (*s)->next;
    free(temp);

    return true;

}

int peek(Stack s){
    return s->data;
}

void display(Stack s){
    Stack temp; 

    initStack(&temp);

    while(!isEmpty(&s)){
        printf("%d ", peek(s));
        push(&temp, peek(s));
        pop(&s);
    }

    while(!isEmpty(&temp)){
        push(&s, peek(temp));
        pop(&temp);
    }

    printf("\n");
}