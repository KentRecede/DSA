#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 8

typedef unsigned char Set;

void initSet(Set *x);
void insert(Set *s, int elem);
bool member(Set *s, int elem);
Set *Union(Set x, Set y);
Set *Intersection(Set x, Set y);
Set *Difference(Set x, Set y);
//Set *Symmetric_Diff(Set x, Set y);
Set *Compliment(Set x);
void display(Set x, char *name);
void displayBits(Set x, char *name);



#endif