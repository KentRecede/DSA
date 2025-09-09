#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "queue.h"
#include "queue.c"

int main(){
    Queue q; 
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