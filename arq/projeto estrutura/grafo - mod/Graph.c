#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

static int **MATRIX(int r, int c, int val) { 
   int **m = malloc(r * sizeof(int *));

   for (int i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof(int));

   for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
         m[i][j] = val;
   
   return m;
}

Graph *Graph_alloc(int V) { 
   Graph *G = malloc(sizeof *G);
   G->numV = V;
   G->numA = 0;
   G->vtx = malloc(V * sizeof(Vertex));
   G->adj = MATRIX(V, V, 0);

   for (int i = 0; i < V; i++){
      G->vtx[i].label = i;
      G->vtx[i].visited = 0;
      G->vtx[i].value = NULL;
   }

   return G;
}

void Graph_free(Graph *G) {
   int i;

   for (i = 0; i < G->numV; i++)
      free(G->adj[i]);

   free(G->adj);
   free(G->vtx);
   free(G);
}

void Graph_insertEdge(Graph *G, int v, int w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->numA++;
   }
}

void Graph_valueVertex(Graph *G, int label, void *value) {
   G->vtx[label].value = value;
}

void Graph_removeEdge(Graph *G, int v, int w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->numA--;
   }
}

Vertex Graph_findByLabel(Graph *G, int label) {
   return G->vtx[label];
} //o seu label é a posição do vértice no vetor

Vertex Graph_findByValue(Graph *G, void *value, int (*cmp)(void*, void*)) {
   int i;
   Vertex val;
   for (i = 0; i < G->numV; i++)
   {
      val = G->vtx[i];
      if (cmp(val.value, value) == 0)
         return val;
   }
   printf("valor não encontrado\n");
}

void Graph_printEdge(Graph *G) {
   printf("   ");
   for (int v = 0; v < G->numV; ++v)
      printf("%2d  ", v);
   printf("\n");

   for (int v = 0; v < G->numV; ++v) {
      printf( "%2d ", v);
      for (int w = 0; w < G->numV; ++w)
         if (G->adj[v][w] == 1) 
            printf( "[1] ");
         else
            printf( "[0] ");
      printf( "\n");
   }
}

//print do vetor de vértices e da matriz de adjacência
void Graph_print(Graph *G) 
{
   void *v;
   int i;

   for (i = 0; i < G->numV; i++)
   {
      v = G->vtx[i].value;

      printf("[");
      printName(v);
      printf("] ");
   }

   printf("\n\n");
   Graph_printEdge(G);
}

void dfs(Graph *G, Vertex v, Vertex *path, int *count) {
   path[*count] = v;

   int i;

   for (i = 0; i < G->numV; i++)
   {
      if (G->adj[v.label][i] == 1) 
      {
         if (G->vtx[i].visited == 0)
         {
            G->vtx[i].visited = 1;
            *count += 1;
            dfs(G, G->vtx[i], path, count);
         }
      }
      if (G->numV == (*count+1))
         break;
   }
}

Vertex *Graph_dfs(Graph *G, void *value, int (*cmp)(void*,void*))
{
   Vertex v = Graph_findByValue(G, value, cmp);
   Vertex *path = calloc(G->numV, sizeof(Vertex));
   int count = 0;

   for (int i = 0; i < G->numV; i++)
      G->vtx[i].visited = 0;

   G->vtx[v.label].visited = 1;
   dfs(G, v, path, &count);
   
   return path;
}

void bfs(Graph *G, Vertex v, Vertex *path, int *count) {
   int i;
   Vertex *pathLocal = calloc(G->numV, sizeof(Vertex));
   int countLocal = 0;

   for (i = 0; i < G->numV; i++)
   {
      if (G->adj[v.label][i] == 1) 
      {
         if (G->vtx[i].visited == 0)
         {
            G->vtx[i].visited = 1;
            *count += 1;
            path[*count] = G->vtx[i];

            pathLocal[countLocal] = G->vtx[i];
            countLocal++;
         }
      }
      if (G->numV == (*count+1))
         break;
   }
   
   for (i = 0; i < countLocal; i++)
   {
      bfs(G, pathLocal[i], path, count);
   }
}

Vertex *Graph_bfs(Graph *G, void *value, int (*cmp)(void*,void*)) {
   Vertex v = Graph_findByValue(G, value, cmp);
   Vertex *path = calloc(G->numV, sizeof(Vertex));
   int count = 0;

   for (int i = 0; i < G->numV; i++)
      G->vtx[i].visited = 0;

   G->vtx[v.label].visited = 1;
   path[count] = v;

   bfs(G, v, path, &count);
   
   return path;
}