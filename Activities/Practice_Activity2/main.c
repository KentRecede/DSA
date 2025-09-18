#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "header.h"
#include "header.c"

int main() {
    Queue prodQ = createQueue();
    ProductStk prodStk;
    
    populateStack(prodStk);
    
    while (prodStk[0].prodID > 0) {
    Product p = prodStk[prodStk[0].prodID];

    if (insertSortedQueueBasedOnExpiryDate(&prodQ, p)) {
        printf("Inserted %s successfully.\n", p.prodName);
    } else {
        printf("Failed to insert %s (queue full).\n", p.prodName);
    }

    prodStk[0].prodID -= 1;
}

    displayTraversal(prodQ);
    
    
    return 0;
}