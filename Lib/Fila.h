#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct elemente{
	int data;
	struct elemente *prox;
}elemente;

typedef struct Queue{
	int size;
	elemente *first, *last;
}Queue;

void new_queue(Queue *queue);
void push_queue(int newElement, Queue *queue);
void pop_queue(Queue *queue);
int front_queue(Queue queue);
void show_queue(Queue queue);
int queue_empty(Queue queue);

#endif