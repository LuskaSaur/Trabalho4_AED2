#include "./Lib/Lista.h"

void new_list(List *list){
	list->size = 0;
	list->first = list->last = NULL;
}

Element* createElement(int data){
	Element *tmp;
	tmp = (Element*)malloc(sizeof(Element));
	tmp->data = data;
	tmp->prox = NULL;
	return tmp;
}

void push_list(int newElement, List *list){
	list->size++;
	if(!list->first){
		list->first = list->last = createElement(newElement);
		return;
	}
	list->last->prox = createElement(newElement);
	list->last = list->last->prox;
}

void show_list(List list){
	Element *tmp = list.first;
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->prox;
	}
	printf("\n");
}