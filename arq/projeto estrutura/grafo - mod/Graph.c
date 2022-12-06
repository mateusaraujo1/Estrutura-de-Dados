#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

static int **MATRIXint(int r, int c, int val) { 
   int **m = malloc(r * sizeof(int *));

   for (vert i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof(int));

   for (vert i = 0; i < r; ++i)
      for (vert j = 0; j < c; ++j)
         m[i][j] = val;
   
   return m;
}

Graph *Graph_alloc(int V) { 
   Graph *G = malloc(sizeof *G);
   G->numV = V;
   G->numA = 0;
   G->vtx = malloc(V * sizeof(Vertex));
   G->adj = MATRIXint(V, V, 0);

   for (int i = 0; i < V; i++){
      G->vtx[i].label = i;
      G->vtx[i].value = NULL;
   }

   return G;
}

void Graph_free(Graph *G) {
   int i;

   for (i = 0; i < G->numV; i++){
      free(G->adj[i]);
      free(G->vtx[i].value);
   }

   free(G->adj);
   free(G->vtx);
   free(G);
}

void Graph_insertEdge(Graph *G, vert v, vert w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->numA++;
   }
}

void Graph_valueVertex(Graph *G, int label, void *value) {
   G->vtx[label].value = value;
}

void Graph_removeEdge(Graph *G, vert v, vert w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->numA--;
   }
}

Vertex Graph_findByLabel(Graph *G, int label) {
   return G->vtx[label];
}

void Graph_printEdge(Graph *G) {
   printf("   ");
   for (vert v = 0; v < G->numV; ++v)
      printf("%2d  ", v);
   printf("\n");

   for (vert v = 0; v < G->numV; ++v) {
      printf( "%2d ", v);
      for (vert w = 0; w < G->numV; ++w)
         if (G->adj[v][w] == 1) 
            printf( "[1] ");
         else
            printf( "[0] ");
      printf( "\n");
   }
}

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

void Graph_print(Graph *G) {

   for (int i = 0; i < G->numV; ++i)
      print(G->vtx[i].value);

}

//gcc Graph.c && a


int main()
{
    Graph *G = Graph_alloc(4);
    Vertex v;

    Aluno a[4] = {
		{"Adao", {7.0,  8.0,  9.0}},
		{"Eva",  {7.5,  10.0, 9.0}},
		{"Caim", {5.0,  8.0,  9.0}},
		{"Abel", {2.0,  6.0,  4.5}}
	};

    Graph_insertEdge(G, 0, 1);
    Graph_insertEdge(G, 0, 2);
    Graph_insertEdge(G, 1, 2);
    Graph_insertEdge(G, 1, 3);
    Graph_insertEdge(G, 2, 3);

    Graph_valueVertex(G, 0, &a[0]);
    Graph_valueVertex(G, 1, &a[1]);
    Graph_valueVertex(G, 2, &a[2]);
    Graph_valueVertex(G, 3, &a[3]);

    printf("matriz de adjacência\n");
    Graph_printEdge(G);

    printf("\nprint dos values\n");
    Graph_print(G);

    printf("\nBuscando e mostrando o label '1'\n");
    v = Graph_findByLabel(G, 1);
    print(v.value);

    Graph_free(G);

    return 0;
}