#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct {
	char nome[10];
	float nota[3];
} Aluno;

int cmp(void *a, void *b) {
    Aluno *a1 = (Aluno*)a;
    char *nome = (char*)b;
    return strcmp(a1->nome, nome);
}

void print(void *a) {
    Aluno *a1 = (Aluno*)a;
    printf("%s %-5.2f %-5.2f %-5.2f\n", a1->nome, a1->nota[0], a1->nota[1], a1->nota[2]);
}

void printName(void *a) {
   Aluno *a1 = (Aluno*)a;
   printf("%s", a1->nome);
}

void Graph_printValue(Graph *G) {
   for (int i = 0; i < G->numV; ++i){
      print(G->vtx[i].value);
   }
}

//gcc Graph.c Graph-main.c -c && gcc Graph.o Graph-main.o && a

int main()
{
   Graph *G = Graph_alloc(7);
   Vertex *path = calloc(G->numV, sizeof(Vertex));
   Vertex v;

   Aluno a[7] = {
		{"Adao",    {7.0,  8.0,  9.0}},
		{"Eva",     {7.5,  10.0, 9.0}},
		{"Caim",    {5.0,  8.0,  9.0}},
		{"Abel",    {2.0,  6.0,  4.5}},
        {"Lilith",  {6.5,  8.0,  8.5}},
        {"Castiel", {9.5,  4.0,  10.0}},
        {"Miguel",  {5.0,  9.0,  1.0}}
	};

   Graph_insertEdge(G, 0, 1);
   Graph_insertEdge(G, 0, 2);
   Graph_insertEdge(G, 1, 3);
   Graph_insertEdge(G, 1, 4);
   Graph_insertEdge(G, 2, 5);
   Graph_insertEdge(G, 2, 6);
   Graph_insertEdge(G, 3, 4);
   Graph_insertEdge(G, 3, 6);
   Graph_insertEdge(G, 4, 0);
   Graph_insertEdge(G, 5, 4);
   Graph_insertEdge(G, 5, 3);
   Graph_insertEdge(G, 6, 5);
    
   //escolhe o label do vértice e insere um value nele
   
   for (int i = 0; i < G->numV; i++)
        Graph_valueVertex(G, i, &a[i]);
   

   printf("\nprint dos values\n");
   Graph_printValue(G);

   printf("\nBuscando e mostrando o label '1'\n");
   v = Graph_findByLabel(G, 1);
   print(v.value);
    
   char nome[10] = "Adao";
   printf("\nBuscando o nome e valores de '%s'\n", nome);
   v = Graph_findByValue(G, &nome, cmp);
   print(v.value);

   printf("\n");
    
   printf("Printando o vetor de vértices e a matriz de adjacência\n");
   Graph_print(G);
   printf("\n");

   printf("\nBusca em profundidade, iniciando por '%s'\n", nome);
   path = Graph_dfs(G, &nome, cmp);

   for (int i = 0; i < G->numV; i++)
      print(path[i].value);

   printf("\nBusca em largura, iniciando por '%s'\n", nome);
   Vertex *path2 = calloc(G->numV, sizeof(Vertex));
   path2 = Graph_bfs(G, &nome, cmp);
   
   for (int i = 0; i < G->numV; i++)
      print(path2[i].value);
   
   Graph_free(G);

   return 0;
}