#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    int date;
    int month;
    int year;
} Date;

typedef struct {
    int prodID;
    char prodName[20];
    Date prodExp;
    float prodPrice;
    int prodQty;
} Product;

typedef struct {
    Product prods[MAX];
    int front;
    int rear;
} Queue;

typedef Product ProductStk[MAX];

void populateStack(ProductStk s);
Product createProduct(int id, char name[], Date dexp, float price, int qty);

int isLeap(int year);
int countDays(Date d);
int dateDifference(Date d1, Date d2);
void displayDate(Date d);

Queue createQueue();
bool enqueue(Queue *q, Product p);
Product dequeue(Queue *q);
Product front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);

void displayTravesal(Queue q);
bool insertSortedQueueBasedOnExpiryDate(Queue *q, Product p);


#endif