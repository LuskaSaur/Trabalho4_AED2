#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Element{
	int data;
	struct Element *prox;
}Element;

typedef struct List{
	int size; 
	struct Element *first, *last;
}List;

void new_list(List *list);
void push_list(int newElement, List *list);
void show_list(List list);

#endif