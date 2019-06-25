#include <stdio.h>
#include <stdlib.h>
#include "./lib/firstlilgraph.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

GRAPH* crategraph(int v){
    // v is the number of vertices
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));
    g->nvertices = v;
    g->nedges = 0;
    g->adj = (VERTICES *)malloc(v*sizeof(VERTICES));
    for(int i =0;i<v;i++){
        g->adj[i].head = NULL;
        g->adj[i].dvertex++;
    }
    return(g);
}

ADJACENCY createadj(int fv, int weight){
    ADJACENCY *tmp;
    tmp = (ADJACENCY *) malloc(sizeof(ADJACENCY));
    tmp->vertex = fv;
    tmp->weight = weight;
    tmp->weight = NULL;
    return(tmp);
}

void createedge(int iv, int fv, GRAPH *g, int weight){
    if(!g){
        printf("Graph don't exist");
        return;
    }
    if((fv<0)||(fv>=g->nvertices)){
        printf("Final Vertex don't exist");
        return;
    }
    if((iv<0)||(iv>=g->nvertices)){
        printf("Initial Vertex dont't exist");
        return;  
    }
    ADJACENCY *tmp = createadj(fv,weight);
    tmp->next = g->adj[iv].head;
    g->adj[iv].head = tmp;
    g->adj[iv].dvertex++;
    g->nedges++;
    return;
}

void bfs(int iv, GRAPH *graph, int *visitvet){
    int count=0, *queue, IQ=0,FQ=0,NV,av;
    for(int i=0;i<graph->nvertices;i++){
        visitvet[i] = -1;
    }
    NV = graph->nvertices;
    queue = (int *)malloc(NV*sizeof(int));
    FQ++;
    queue[FQ] = iv;
    visitvet[iv] = count;
    ADJACENCY *tmp;
    while(IQ!=FQ){
        IQ = (IQ+1) % NV;
        av = queue[IQ];
        count++;
        tmp = graph->adj[av].head;
        for(int i=0;i<graph->adj[av].dvertex;i++){
            if(visitvet[tmp->vertex] == -1){
               FQ = (FQ+1)%NV;
               queue[FQ] = tmp->vertex;
               visitvet[tmp->vertex] = count;
               tmp = tmp->next; 
            }
        }
    }
    free(queue);
}

void dfs(int color[], int i, GRAPH *g){
    color[i] = GRAY;
    ADJACENCY *v = g->adj[i].head;
    while(v){
        if(color[v->vertex] == WHITE)
            dfs(color,v->vertex,g)
        v = v->next;
    }
    color[i] = BLACK; 
}
void depth(GRAPH *g){
    int color[g->nvertices];
    for(int i =0;i<g->nvertices;i++){
        color[i] = WHITE;
    }
    for(int i =0;i<g->nvertices;i++){
        if(color[i] == WHITE){
            dfs(color,i,g);
        }
    }
}
