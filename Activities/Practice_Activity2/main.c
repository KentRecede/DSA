#include <stdio.h>
#include <stdbool.h>

#include "header.h"
#include "header.c"

int main() {
    Queue prodQ = createQueue();
    ProductStk prodStk;
    
    populateStack(prodStk);
    
    while(prodStk[0].prodID > 0) {
        printf("%s\n", prodStk[prodStk[0].prodID].prodName);
        prodStk[0].prodID -= 1;
    }
    
    
    
    
    return 0;
}