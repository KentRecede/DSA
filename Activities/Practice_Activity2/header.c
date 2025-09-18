#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "header.h"

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int countDays(Date d) {
    static int monthDays[12] = {31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31};
    int days = d.year * 365 + d.date;

    for (int i = 0; i < d.month - 1; i++)
        days += monthDays[i];

    days += d.year / 4 - d.year / 100 + d.year / 400;

    if (isLeap(d.year) && d.month > 2)
        days += 1;

    return days;
}

int dateDifference(Date d1, Date d2) {
    return countDays(d2) - countDays(d1);
}

void displayDate(Date d) {
    char monthName [12][5] = {"Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec",
    };
    
    printf("%02d %s %d", d.date, monthName[d.month], d.year);
}

Queue createQueue() {
    Queue q;
    
    q.front = 0;
    q.rear = MAX - 1;
    
    return q;
}

bool enqueue(Queue *q, Product p) {
    if(isFull(*q)) {
        return false;
    }
    
    q->rear = (q->rear + 1) % MAX;
    q->prods[q->rear] = p;
    
    return true;
}

// we could not call this one if empty
Product dequeue(Queue *q) {
    Product p = q->prods[q->front];
    q->front = (q->front + 1) % MAX;
   
    return p;
}

// we could not call this one if empty
Product front(Queue q) {
    return q.prods[q.front];
}

bool isEmpty(Queue q) {
    return (q.rear + 1) % MAX == q.front;    
}

bool isFull(Queue q) {
    return (q.rear + 2) % MAX == q.front;    
}

void displayTraversal(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("%10s | %10s | %11s | %10s | %s\n",
           "ID", "NAME", "DATE EXPIRY", "PRICE", "QTY");

    for (int i = q.front; i != (q.rear + 1) % MAX; i = (i + 1) % MAX) {
        Product p = q.prods[i];

        printf("%10d | %10s | ", p.prodID, p.prodName);
        displayDate(p.prodExp);
        printf(" | Php %6.2f | %d\n", p.prodPrice, p.prodQty);
    }

    printf("\n");
}


Date createDate(int date, int month, int year) {
    Date d;
    
    d.date = date;
    d.month = month;
    d.year = year;
    
    return d;
}

Product createProduct(int id, char name[], Date dexp, float price, int qty) {
    Product p;
    
    p.prodID = id;
    strcpy(p.prodName, name);
    p.prodExp = dexp;
    p.prodPrice = price;
    p.prodQty = qty;
    
    return p;
}

void populateStack(ProductStk s) {
    s[0] = createProduct(3, "", createDate(0, 0, 0), 0.0, 0);
    s[1] = createProduct(1005, "Binangkal", createDate(1, 6, 2026), 12.50, 40);
    s[2] = createProduct(1010, "Bingka", createDate(9, 7, 2027), 20.00, 5);
    s[3] = createProduct(1020, "Budbud", createDate(12, 5, 2027), 20.00, 5);
}

bool insertSortedQueueBasedOnExpiryDate(Queue *q, Product p) {
    if (isFull(*q)) {
        return false;  
    }

    Queue temp = createQueue();
    bool inserted = false;

    while (!isEmpty(*q)) {
        Product curr = dequeue(q);

        if (!inserted && dateDifference(p.prodExp, curr.prodExp) < 0) {
            enqueue(&temp, p);
            inserted = true;
        }

        enqueue(&temp, curr);
    }

    // If still not inserted, append at the end
    if (!inserted) {
        enqueue(&temp, p);
    }

    *q = temp;
    return true;  // success
}
