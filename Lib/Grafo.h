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

void create_graph(int number_componentes, int per_connectivity, int number_vertices, Graph *graph); //Create a Graph with n components
void create_graph_connected(int per_connectivity, int number_vertices, Graph *graph);//Create a connected graph
void show_adjList_vertices(Graph graph);//Show the adjList of each vertice
void DFS_Stack(Graph graph);//Dfs using stack instead recursive
void DFS_Recursive_Caller(Graph graph);//Recursive Dfs caller
void DFS_Recursive(int cur, Graph *graph, int *vis);//Recursive Dfs
void BFS(Graph graph);//standard Bfs
void Finding_Cycles(Graph graph);//Finding cycles with Dfs
void all_way_graph_caller(Graph graph);//Call the all way in graph, maked with Backtracking
void all_way_graph(int cur, Graph *graph, char *sequence, int size);//Print all the ways in a Graph caller

#endif 