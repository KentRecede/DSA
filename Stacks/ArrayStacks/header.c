#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

void initStack(Stack *s){
    s->top = -1;
}

bool isEmpty(Stack *s){
    return s->top == -1;
}

bool isFull(Stack *s){
    return s->top == MAX - 1;
}

bool push(Stack *s, int data){
    if(isFull(s)){
        return false;
    };

    s->arr[++s->top] = data;

    return true;
}

bool pop(Stack *s){
    if(isEmpty(s)){
        return false;
    }

    s->top--;
    
    return true;
}

int peek(Stack *s){
    return s->arr[s->top];
}

void display(Stack s){
    for(int i = s.top; i >= 0; i--){
        printf("%d ",s.arr[i]);
    }
    printf("\n");
}

