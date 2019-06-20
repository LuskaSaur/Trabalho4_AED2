#include <stdio.h>
#include "./Lib/Lista.h"
#include "./Lib/Pilha.h"
#include "./Lib/Fila.h"
#include "./Lib/Grafo.h"

//gcc Grafo.c Fila.c Pilha.c Lista.c main.c -o main

int main(){
	Graph graph;
	//create_graph_connected(20,7,&graph);
	create_graph(3, 10, 12, &graph);
	show_adjList_vertices(graph);
	printf("DFS-Recursive sequence: \n");
	DFS_Recursive_Caller(graph);
	printf("DFS-Stack sequence: \n");
	DFS_Stack(graph);
	printf("BFS sequence: \n");
	BFS(graph);
	printf("Cycles: \n");
	Finding_Cycles(graph);
	printf("Ways in Graph: \n");
	all_way_graph_caller(graph);
}