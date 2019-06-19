#include "./Lib/Pilha.h"

void new_stack(Stack *stack){
	stack->size = 0;
	stack->first = NULL;
}

int top(Stack stack){
	return stack.first->data;
}

element* createElemente(int data){
	element *tmp;
	tmp = (element*)malloc(sizeof(element));
	tmp->prox = NULL;
	tmp->data = data;
	return tmp;
}

void push_stack(int newElement, Stack *stack){
	element *tmp;
	tmp = stack->first;
	stack->first = createElemente(newElement);
	stack->first->prox = tmp;
	stack->size++;
}

void pop_stack(Stack *stack){
	element *tmp;
	tmp = stack->first->prox;
	free(stack->first);
	stack->first = tmp;
	stack->size--;
}

void show_stack(Stack stack){
	element *tmp = stack.first;
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->prox;
	}
	printf("\n");
}

int stack_empty(Stack stack){
	return (stack.size == 0);
}