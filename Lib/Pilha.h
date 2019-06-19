#ifndef PILHA_H
#define PILHA_H
#include <stdlib.h>
#include <stdio.h>

typedef struct element{
	int data;
	struct element *prox;
}element;

typedef struct Stack{
	int size;
	struct element *first;
}Stack;

void new_stack(Stack *stack);
int top(Stack stack);
void push_stack(int newElement, Stack *stack);
void pop_stack(Stack *stack);
void show_stack(Stack stack);
int stack_empty(Stack stack);

#endif