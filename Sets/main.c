#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary.h"
#include "dictionary.c"

int main(){
    Set A, B;

    initSet(&A);
    initSet(&B);

    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);
    
    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 7);

    display(A, "A");
    displayBits(A, "A");

    display(B, "B");
    displayBits(B, "B");

    Set *U = Union(A, B);
    display(*U, "Union");

    Set *I = Intersection(A, B);
    display(*I, "Intersection");

    Set *D = Difference(A, B);
    display(*D, "Difference");

    Set *C = Compliment(A);
    display(*C, "Compliment");


    return 0;

}