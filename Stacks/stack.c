#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

void initStack(Node *link){
    *link = NULL;
}

bool isEmpty(Node *link){
    return (*link) == NULL;
}

bool isFull(Node *link){
    return false;
}

bool push(Node *link, int data){
    Node temp = malloc(sizeof(struct node));

    if(!temp){
        return false;
    }

    temp->data = data;
    temp->next = *link;
    *link = temp;

    return true;

}

bool pop(Node *link){

    if(*link == NULL){
        return false;
    }

    Node temp = *link;

    *link = (*link)->next;
    free(temp);

    return true;
}

int peek(Node *link){
    return (*link)->data;
}


void display(Node link){
    Node temp = link;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}