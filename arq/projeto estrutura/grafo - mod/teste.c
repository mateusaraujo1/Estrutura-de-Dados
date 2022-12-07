#include <stdio.h>
#include "Graph.h"

Vertex buscaProximo(Graph *G, Vertex v) {
    int i;
    int **mat = G->adj;
    Vertex k;
    for (i = 0; i < G->numV; i++)
    {
        if (mat[v.label][i] == 1) 
        {
            if (G->vtx[i].visited == 0)
            {
                return G->vtx[i];
            }
        }
    }

    int conta = 0;
    for (i = 0; i < G->numV; i++)
    {
        if (G->vtx[i].visited == 1)
        {
            conta++;
        }
    }

    if (conta == G->numV)
    {
        k.visited = 101; //indica que todos já foram visitados
    }else
    {
        k.visited = 101; //indica que ainda falta visitar mais vtx
    }
    
    
    
    return k;
}

static void dfs(Graph *G, Vertex v, Vertex *path, int *count) {
    Vertex k;
    v.visited = 1;
    path[*count] = v;

    while (k.visited != 101)
    {
        k = buscaProximo(G, v);
        if (k.visited != 101)
        {
            *count += 1;
            dfs(G, k, path, &count);
        }
    }
}

Vertex **Graph_dfs(Graph *G, void *startValue, int (*cmp)(void*,void*)) {
    Vertex * path, v;
    int i, count = 0;
    int **matriz = G->adj;
    

    for (i = 0; i < G->numV; i++)
        G->vtx[i].visited = 0;

    v = Graph_findByValue(G, startValue, cmp);
    path = calloc(G->numV, sizeof(Vertex));

    dfs(G, v, path, &count);

    return path;
}