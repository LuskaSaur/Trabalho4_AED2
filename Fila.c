#include "./Lib/Fila.h"

elemente* create_e_queue(int data){
	elemente* tmp = (elemente *)malloc(sizeof(elemente));
	tmp->data = data;
	tmp->prox = NULL;
	return tmp;
}

void new_queue(Queue *queue){
	queue->first = NULL;
	queue->size = 0;
}

void push_queue(int newElement, Queue *queue){
	queue->size++;
	if(!queue->first){
		queue->first = queue->last = create_e_queue(newElement);
		return;
	}
	queue->last->prox = create_e_queue(newElement);
	queue->last = queue->last->prox;
}

void pop_queue(Queue *queue){
	elemente *tmp;
	tmp = queue->first;
	queue->first = queue->first->prox;
	free(tmp);
	queue->size--;
}

int front_queue(Queue queue){
	return queue.first->data;
}

void show_queue(Queue queue){
	elemente *tmp;
	tmp = queue.first;
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->prox;
	}
	printf("\n");
}

int queue_empty(Queue queue){
	return (queue.size == 0);
}