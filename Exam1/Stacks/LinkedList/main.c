#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"
#include "header.c"

int main(){
    Stack s;

    initStack(&s);

    push(&s, 10);
    display(s);
    push(&s, 20);
    display(s);
    push(&s, 30);
    display(s);

    return 0;
}