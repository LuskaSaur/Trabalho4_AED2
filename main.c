#include <stdio.h>
#include <time.h>
#include "./Lib/Lista.h"
#include "./Lib/Pilha.h"
#include "./Lib/Fila.h"
#include "./Lib/Grafo.h"

//gcc Grafo.c Fila.c Pilha.c Lista.c main.c -o main

//To do: Criar funcao que gera grafos sem ciclo.

const int number_of_vertices = 10;
const int percentual_connectivity = 20;
const int DEBUG = 0;

int main(){
	clock_t t[2];
	Graph graph, agraph;
	double aver = 0.0, aver1 = 0.0;

	//1) Criar grafos conexos com diferentes quantidades de vértices e graus de conectividade.
	printf("\n1) Chamando funcao que cria o grafo conexos\n");
	create_graph_connected(percentual_connectivity, number_of_vertices, &graph);//Porcertangem de conectividade, numero de vértices e Grafo
	create_graph_acyclic(percentual_connectivity, number_of_vertices, &agraph);//Cria um grafo acíclico
	printf("Grafo Criado\n");

	//2) Busca em Largura – mostrar a árvore resultante do caminhamento; marcar tempo de execução para cada busca e a média das buscas.
	printf("\n2) Teste de tempo para busca em largura\n");
	printf("Caminhos em cada busca: \n\n");
	aver = 0.0;
	for(int i=1; i <= 30; i++){
		t[0] = clock();
		BFS(graph, i%number_of_vertices);
		t[1] = clock();
		if(DEBUG)
			printf("Tempo na %d busca em largura: %lf\n", i, ((double)t[1] - t[0])/(CLOCKS_PER_SEC/1000));
		aver += ((double)t[1] - t[0])/(CLOCKS_PER_SEC/1000);
	}
	printf("\nTempo medio na busca em largura: %lf\n\n", aver/30.0);
	

	//3) Busca em Profundidade – mostrar a sequência de vértices visitados; marcar tempo de execução para cada busca e a média das buscas.
	printf("3) Teste de tempo para busca em profundidade\n");
	printf("Caminhos em cada busca: \n\n");
	aver = aver1 = 0.0;
	for(int i=1; i <= 30; i++){
		//DFS with stack
		t[0] = clock();
		DFS_Stack(graph, i%number_of_vertices);
		t[1] = clock();
		if(DEBUG)
			printf("Tempo na %d busca em profundidade usando pilha: %lf\n", i, ((double)t[1] - t[0])/(CLOCKS_PER_SEC/1000));
		aver += ((double)t[1] - t[0])/(CLOCKS_PER_SEC/1000);
		//DFS recursive
		t[0] = clock();
		DFS_Recursive_Caller(graph, i%number_of_vertices);
		t[1] = clock();
		if(DEBUG)
			printf("Tempo na %d busca em profundidade recursiva: %lf\n", i, ((double)t[1] - t[0])/(CLOCKS_PER_SEC/1000));
		aver1 += ((double)t[1] - t[0])/(CLOCKS_PER_SEC/1000);
	}
	/*
		>> numero_de_chamadas_de_funcs_v_pilha > numero_de_chamadas_de_funcs_v_recursiva <<
		Na maioria dos casos o tempo da busca usando pilha vai ser maior que o tempo da recursiva,
		isso se deve ao fato de que a versao a pilha utiliza uma pilha feita via ponteiros e funcoes
		caso a pilha fosse implementada utilizando um vetor o resultado seria melhor. Pois haveria menos
		chamadas de funcs no uso da versao a pilha.
		Isso tambem cabe para a busca em largura!
	*/
	printf("\nTempo medio na busca em profundidade com pilha: %lf\n", aver/30.0);
	printf("Tempo medio na busca em profundidade recursiva: %lf\n\n", aver1/30.0);

	//4) Todos os caminhos usando busca em profundidade – mostrar todas as sequências de vértices geradas. Usar um grafo de tamanho adequado ao exercício.
	printf("4) Mostrar todos os possiveis caminhos no Grafo: \n");
	printf("Caminhos: \n\n");
	all_way_graph_caller(graph);
	printf("\n");

	/*	 5) Determinar se um dado grafo possui ciclo, usando busca em profundidade. 
	 *		Testar diferentes grafos com e sem ciclos, de diversos tamanhos e graus de conectividade.
	 */
	printf("5) Determinar se um dado grafo possui ou nao ciclos: \n");
	if(Finding_Cycles(agraph))
		printf("Este grafo possui um ciclo\n");

	//FIM TRABALHO 4
	return 0;
}	