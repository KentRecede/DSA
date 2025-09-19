#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"
#include "header.c"

int main(){
    LLQueue q;

    initQueue(&q);


    enqueue(&q, 10);
    display(q);
    enqueue(&q, 20);
    display(q);
    enqueue(&q, 30);
    display(q);
    dequeue(&q);
    display(q);


    return 0;
}