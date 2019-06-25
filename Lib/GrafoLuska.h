#include <stdio.h>
#ifndef FIRSTLILGRAPH_H
#define FIRSTLILGRAPH_H

typedef struct adjacency{
    int vertex;
    float weight;
    struct adjacency *next;
}ADJACENCY;

typedef struct vertices{
    ADJACENCY *head;
    int dvertex;
}VERTICES;

typedef struct graph{
    int nvertices;
    int nedges;
    VERTICES *adj;
}GRAPH;


GRAPH* crategraph(int v);

ADJACENCY createadj(int fv, int weight);

void createedge(int iv, int fv, GRAPH *g, int weight);

void bfs(int iv, GRAPH *graph, int *visitvet);

void dfs(int color[], int i, GRAPH *g);

void depth(GRAPH *g);
