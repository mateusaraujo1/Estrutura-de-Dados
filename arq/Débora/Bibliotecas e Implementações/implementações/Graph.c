#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

Graph *Graph_create(int (*compar)(void*, void*)){
  Graph *g = malloc(sizeof(Graph));
  if(g && compar){
    g->numberVertices = 0;
    g->first = NULL;
    g->compar = compar;
  }
  return g;
}

void Graph_destroy(Graph *g){
  if(g){
    Vertex_destroy(g->first);
    free(g);
  }
}

void Graph_insert(Graph *g, void *value){
  Vertex *new = NULL;
  if(g && value){
    new = Vertex_create(value);
    new->next = g->first;
    g->first = new;
    g->numberVertices++;
  }
}

void Graph_link(Graph *g, void *value1, void *value2){
  if(g){
    Vertex *v1 = Vertex_find(g, value1);
    Vertex *v2 = Vertex_find(g, value2);
    Edge *new = NULL;
    if(v1 && v2){
      Edge *new = Edge_create();
      new->origin = v1;
      new->target = v2;
      if(v1->numberLinks > 0)
        new->next = v1->first;
      v1->first = new;
      v1->numberLinks++;
    }
  }
}

void Graph_print(Graph *g, void (*print)(void *)){
  Vertex *v = NULL;
  Edge *e = NULL;
  if(g && print){
    v = g->first;
    while(v){
      printf("Vertice ");
      print(v->value);
      printf("\n\tVizinhos: ");
      e = v->first;
      while(e){
        print(e->target->value);
        printf(" ");
        e = e->next;
      }
      printf("\n");
      v = v->next;
    }
  }
}

int Graph_numberVertex(Graph *g){
  return g->numberVertices;
}

Vertex *Vertex_create(void *value){
  Vertex *v = malloc(sizeof(Vertex));
  if(v){
    v->value = value;
    v->first = NULL;
    v->next = NULL;
    v->numberLinks = 0;
  }
  return v;
}

void Vertex_destroy(Vertex *v){
  Vertex *temp = NULL;
  if(v){
    while(v){
      Edge_destroy(v->first);
      temp = v;
      v = v->next;
      free(temp);
    }
  }
}

int Vertex_occasion(Graph *g, void *value){
  Vertex *v = NULL;
  Edge *e = NULL;
  int n = 0;
  if(g && value){
    v = g->first;
    while(v){
      e = v->first;
      while(e){
        if(g->compar(value, e->target->value) == 0)
          n++;
        e = e->next;
      }
      v = v->next;
    }
  }
  return n;
}

Vertex *Vertex_BiggerOccasion(Graph *g){
  Vertex *v = NULL;
  Vertex *vMaior = NULL;
  int maior = 0;
  int cur = 0;
  if(g){
    v = g->first;
    while(v){
      cur = Vertex_occasion(g, v->value);
      if(cur > maior){
        maior = cur;
        vMaior = v;
      }
      v = v->next;
    }
  }
  return vMaior;
}

void Vertex_segueMaior(Graph *g){
  Vertex *v = NULL;
  Edge *e = NULL;
  int n = 0;
  pessoas targetPessoas;
  pessoas originPessoas;
  if(g){
    v = g->first;
    while(v){
      e = v->first;
      while(e){
        targetPessoas = *(pessoas*)e->target->value;
        originPessoas = *(pessoas*)e->origin->value;
        if(targetPessoas.idade > originPessoas.idade)
          n = 1;
        else{
          n = 0;
          break;
        }
        e = e->next;
      }
     if(n == 1)
       printf("Nome: %s\n",  originPessoas.nome);
      n = 0;
      v = v->next;
    }
  }
}

Vertex *Vertex_find(Graph *g, void *value){
  Vertex *cur = NULL;
  if(g && value){
    cur = g->first;
    while(cur){
      if(g->compar(value, cur->value) == 0)
        break;
      cur = cur->next;
    }
  }
  return cur;
}

int Vertex_numberLinks(Graph *g, void *value){
  Vertex *v1 = Vertex_find(g, value);
  return v1->numberLinks;
}

Edge *Edge_create(){
  Edge *e = malloc(sizeof(Edge));
  if(e){
    e->next = NULL;
    e->origin = NULL;
    e->target = NULL;
  }
  return e;
}

void Edge_destroy(Edge *e){
  Edge *temp = NULL;
  if(e){
    while(e){
      temp = e;
      e = e->next;
      free(temp);
    }
  }
}

void Edge_delete(Graph *g, void *value1, void *value2){
  Vertex *curVertex = Vertex_find(g, value1);
  Edge *curEdge = NULL, *forEdge = NULL;
  if(curVertex){
    curEdge = curVertex->first;
    while(curEdge && (curEdge->target->value != value2)){
      forEdge = curEdge;
      curEdge = curEdge->next;
    }
    if(forEdge == NULL)
      curVertex->first = curEdge->next;
    else
      forEdge->next = curEdge->next;
    free(curEdge);
    curVertex->numberLinks--;
  }
}

Edge *Edge_find(Graph *g, void *value1, void *value2){
  Vertex *origin = Vertex_find(g, value1);
  Edge *cur = NULL;
  if(g && origin && value2){
    Edge *cur = origin->first;
    while(cur){
      if(g->compar(value2, cur->target->value) == 0)
        break;
      cur = cur->next;
    }
  }
  return cur;
}
