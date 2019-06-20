#include "./Lib/Grafo.h"

void create_graph(int number_componentes, int per_connectivity, int number_vertices, Graph *graph){
	per_connectivity = per_connectivity%101;
	int newVert = (per_connectivity * (number_vertices - 1))/100;
	if(newVert < 1)
		return;
	graph->number_vertices = number_vertices;
	graph->adjList = (List *)malloc(sizeof(List) * number_vertices);
	int vertices_per_components = number_vertices/number_componentes;
	for(int i=0; i<number_componentes; ++i){
		for(int j=i*vertices_per_components; j<vertices_per_components*(i+1); ++j){
			if(j == ((vertices_per_components*(i+1))-1) )
				push_list(i*vertices_per_components, &graph->adjList[j]);
			else
				push_list(j+1, &graph->adjList[j]);
		}
	}
	newVert--;
	if(newVert < 1)
		return;
	for(int i=0; i<number_vertices; i++){
		int first_component = (i/number_componentes) * number_componentes;
		//printf("i = %d and first = %d\n", i, first_component);
		for(int j=0, k=0, vert = first_component; j<number_vertices, k<newVert; j++, vert++){
			printf("i = %d - first_component = %d - vert = %d\n", i, first_component, vert);
			vert = vert%number_vertices;
			if(vert != i){
				if(first_component+vertices_per_components-1 == i){
					if(vert != first_component){
						push_list(vert, &graph->adjList[i]);
						k++;
					}
				}
				else{
					if(vert != i+1){
						push_list(vert, &graph->adjList[i]);
						k++;
					}
				}
			}
		}
	}
}

void create_graph_connected(int per_connectivity, int number_vertices, Graph *graph){
	per_connectivity = per_connectivity%101;
	int newVert = (per_connectivity * (number_vertices - 1))/100;
	graph->number_vertices = number_vertices;
	graph->adjList = (List*)malloc(sizeof(List) * number_vertices);
	if(newVert < 1)
		return;
	for(int i=0; i<number_vertices; i++){
		int next_vertice = (i+1)%number_vertices;
		push_list(next_vertice, &graph->adjList[i]);
	}
	newVert--;
	if(newVert < 1)
		return;
	for(int i=0; i<number_vertices; i++){
		for(int j=0, k=0; j<number_vertices, k<newVert; j++){
			if(j != (i+1)%number_vertices && (j!= i)){
				push_list(j, &graph->adjList[i]);
				k++;
			}
		}
	}
}

void show_adjList_vertices(Graph graph){
	int n = graph.number_vertices;
	for(int i=0; i<n; i++){
		printf("Vertice %d: \n", i);
		show_list(graph.adjList[i]);
	}
}

void DFS_Stack(Graph graph){
	int *vis = (int*)malloc(sizeof(int) * graph.number_vertices);
	for(int i=0; i<graph.number_vertices; i++)
		vis[i] = -1;
	Stack stack;
	new_stack(&stack);
	push_stack(0, &stack);
	vis[0] = 1;
	while(!stack_empty(stack)){
		int cur = top(stack);
		printf("%d ", cur);
		pop_stack(&stack);
		for(Element* it = graph.adjList[cur].first; it != NULL; it = it->prox){
			if(vis[it->data] == -1){
				vis[it->data] = 1;
				push_stack(it->data, &stack);
			}
		}
	}
	printf("\n");
}

void DFS_Recursive_Caller(Graph graph){
	int *vis = (int*)malloc(sizeof(int) * graph.number_vertices);
	for(int i=0; i<graph.number_vertices; i++)
		vis[i] = -1;
	vis[0] = 1;
	DFS_Recursive(0, &graph, vis);
	printf("\n");
}

void DFS_Recursive(int cur, Graph *graph, int *vis){
	printf("%d ", cur);
	for(Element *it = graph->adjList[cur].first; it != NULL; it = it->prox){
		int act = it->data;
		if(vis[act] == -1){
			vis[act] = 1;
			DFS_Recursive(act, graph, vis);
		}
	}
}

void BFS(Graph graph){
	int *vis = (int*)malloc(sizeof(int) * graph.number_vertices);
	for(int i=0; i<graph.number_vertices; i++)
		vis[i] = -1;
	Queue queue;
	new_queue(&queue);
	push_queue(0, &queue);
	vis[0] = 1;
	while(!queue_empty(queue)){
		int cur = front_queue(queue);
		printf("%d ", cur);
		pop_queue(&queue);
		for(Element *it = graph.adjList[cur].first; it != NULL; it = it->prox){
			int act = it->data;
			if(vis[act] == -1){
				vis[act] = 1;
				push_queue(act, &queue);
			}
		}
	}
	printf("\n");
}

void Finding_Cycles(Graph graph){
	int *vis = (int*)malloc(sizeof(int) * graph.number_vertices);
	for(int i=0; i<graph.number_vertices; i++)
		vis[i] = -1;
	Stack stack;
	new_stack(&stack);
	push_stack(0, &stack);
	vis[0] = 1;
	while(!stack_empty(stack)){
		int cur = top(stack);
		pop_stack(&stack);
		for(Element* it = graph.adjList[cur].first; it != NULL; it = it->prox){
			if(vis[it->data] == -1){
				vis[it->data] = 1;
				push_stack(it->data, &stack);
			}
			else
				printf("A cycle has been founded!\n");
		}
	}
}

void all_way_graph_caller(Graph graph){
	char *sequence = (char*)malloc(sizeof(char) * (graph.number_vertices + 1));
	for(int i=0; i<graph.number_vertices; i++)
		all_way_graph(i, &graph, sequence, 0);
}

void all_way_graph(int cur, Graph *graph, char *sequence, int size){
	if(size == graph->number_vertices){
		sequence[size] = '\0';
		printf("%s\n", sequence);
		return;
	}	
	for(Element *it = graph->adjList[cur].first; it != NULL; it = it->prox){
		int act = it->data, valid = 1;
		for(int i=0; i<size; i++)
			if(act == (sequence[i] - '0'))
				valid = 0;
		if(valid == 0)
			continue;
		else{
			sequence[size] = act + '0';
			all_way_graph(act, graph, sequence, size+1);
		}
	}
}