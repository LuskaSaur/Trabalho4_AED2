#ifndef	GRAFO_H
#define GRAFO_H
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Graph{
	int number_vertices;
	List *adjList;
}Graph;

void create_graph(int number_componentes, int per_connectivity, int number_vertices, Graph *graph);
void create_graph_connected(int per_connectivity, int number_vertices, Graph *graph);
void show_adjList_vertices(Graph graph);
void DFS_Stack(Graph graph);
void DFS_Recursive_Caller(Graph graph);
void DFS_Recursive(int cur, Graph *graph, int *vis);
void BFS(Graph graph);
void Finding_Cycles(Graph graph);
void all_way_graph_caller(Graph graph);
void all_way_graph(int cur, Graph *graph, char *sequence, int size);

#endif 