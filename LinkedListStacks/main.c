#include <stdio.h>
#include <stdbool.h>

#include "stack.c"
#include "stack.h"

int main(){
    Node list;
    initStack(&list);

    push(&list, 10);
    display(list);

    push(&list, 20);
    display(list);

    push(&list, 30);
    display(list);

    pop(&list);
    display(list);

    printf("%d", peek(&list));

    return 0;
}
