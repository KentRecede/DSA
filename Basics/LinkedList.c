#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}*List;


void initList(List *list);
bool insertFront(List *list, int data);
bool insertRear(List *list, int data);
bool insertAt(List *list, int data, int pos);
bool insertSorted(List *list, int data);
bool deleteFront(List *list);
bool deleteRear(List *list);
void display(List list);

void initList(List *list){
    *list = NULL;
}

bool insertFront(List *list, int data){
    List temp = malloc(sizeof(struct node));

    if(!temp){
        return false;
    }

    temp->data = data;
    temp->next = *list;
    *list = temp;

    return true;
}

bool insertRear(List *list, int data){
    List temp = malloc(sizeof(struct node));

    if(!temp){
        return false;
    }

    List curr = *list;
    if(*list == NULL){
        *list = temp;
    }else{
        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = temp;
    }

    return true;
}

bool insertAt(List *list, int data, int pos){

    List temp = malloc(sizeof(struct node));

    if(!temp){
        return false;
    }

    temp->data = data;
    int index = 0;
    List curr = *list;
    if(pos == 1){
        temp->next = *list;
        *list = temp;

        return true;
    }

    while(curr->next != NULL && index < pos -1 ){
        curr = curr->next;
        index++;
    }

        temp->next = curr->next;
        curr->next = temp;
    

    return true;

}

bool insertSorted(List *list, int  data){
    List temp = malloc(sizeof(struct node));

    if(!temp){
        return false;
    }

    temp->data = data;

    List curr = *list;
    if(*list == NULL || (*list)->next->data >= data){
        temp->next = *list;
        *list = temp;
    }


    while(curr->next != NULL && curr->next->data < data){
        curr = curr->next;
    }

        curr->next = temp->next;
        temp = *list;
    

    return true;
}


