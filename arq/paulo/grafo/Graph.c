#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Graph.h"
#include "Queue.h"
#include "Heap.h"

Graph *Graph_alloc() {
    Graph *g = malloc(sizeof(Graph));
    
    if (g) {
        g->n = 0;
        g->first = NULL;
        g->last = NULL;
    }
    
    return g;
}

void Graph_free(Graph *g) {
    Edge *e = NULL, *eaux;
    Vertex *v = NULL, *vaux;
    
    if (g) {
        v = g->first;
        
        while (v) {
            vaux = v->next;
            
            e = v->first;
            while (e) {
                eaux = e->next;
                free(e);
                e = eaux;
            }
            
            free(v);
            v = vaux;
        }
        
        free(g);
    }
}

void Graph_insertVertex(Graph *g, void *value) {
    Vertex *new = NULL;
    
    if (g) {
            new = malloc(sizeof(Vertex));
            new->n = 0;
            new->visited = 0;
            new->label = g->n;
            new->value = value;
            new->first = NULL;
            new->last = NULL;
            new->next = NULL;
            
            if (g->n == 0) {
                g->first = new;
                g->last = new;
            }
            else {
                g->last->next = new;
                g->last = new;
            }
            
            g->n++;
    }
}

Vertex *Graph_findByLabel(Graph *g, int label) {
    Vertex *v = NULL;
    
    if (g) {
        v = g->first;
        
        while (v) {
            if (v->label == label)
                return v;
            v = v->next;
        }
    }
    
    return NULL;
}


void Graph_insertEdge(Graph *g, int label1, int label2, void *value) {
    Edge *new = NULL, *e = NULL;
    Vertex *tail, *head;
    
    if (g) {
        tail = Graph_findByLabel(g, label1);
        head = Graph_findByLabel(g, label2);
        
        if (tail && head) {
            new = malloc(sizeof(Edge));
            new->tail = tail;
            new->head = head;
            new->value = value;
            new->next = NULL;
            
            if (tail->n == 0) {
                tail->first = new;
                tail->last = new;
            }
            else {
                tail->last->next = new;
                tail->last = new;
            }
            
            tail->n++;
        }
    }
}

void Graph_removeEdge(Graph *g, int label1, int label2) {
	Vertex *tail = NULL, *head = NULL;
	Edge *e = NULL, *ant = NULL;
	
	if (g) {
		tail = Graph_findByLabel(g, label1);
		head = Graph_findByLabel(g, label2);
		
		if (tail && head) {
			e = tail->first;
			
			while (e) {
				if (e->head->label == label2) {
          if (ant == NULL) {
            tail->first = e->next;
          }
          else {
            ant->next = e->next;

          if (e->next == NULL)
            tail->last = ant;
          }

          tail->n--;

          free(e);
          break;
				}
				
				ant = e;
				e = e->next;
			}
		}
	}
}

void Graph_removeVertex(Graph *g, int label) {
    Edge *e = NULL, *eaux;
    Vertex *v = NULL, *vaux = NULL, *ant = NULL;
    int i;
    
    if (g) {
        v = g->first;
        
        while (v) {
            if (v->label == label) {
                
				for (i=0; i < g->n; i++) {
					Graph_removeEdge(g, i, v->label);
				}

				if (ant == NULL) {
					g->first = v->next;
				} 
				else {
					ant->next = v->next;
					
					if (v->next == NULL)
						g->last = ant;			
				}

				e = v->first;
				
				while (e) {
					eaux = e->next;
					free(e);
					e = eaux;
				}

				g->n--;
				
				free(v);
				break;
            }
            
            ant = v;
            v = v->next;
        }
    }
}

void Graph_print(Graph *g, void (*print)(void *value)) {
    Vertex *v = NULL;
    Edge *e = NULL;
    
    if (g) {
		printf("Graph(%d):\n", g->n);
		
        v = g->first;
        
        if (print) {
			while (v) {
				printf("\t[");
				print(v->value);
				printf(" /%d]->", v->n);
			
				e = v->first;
				while (e) {
					printf("("); 
					print(e->head->value);
					printf(")->");
					e = e->next;
				}

				printf("\n");
				v = v->next;
			}
		}
		else {
			while (v) {	
				printf("\t[%d /%d]->", v->label, v->n);
				
				e = v->first;
				while (e) {
					printf("(%d)->", e->head->label);
					e = e->next;
				}

				printf("\n");
				v = v->next;
			}
		}
    }
}


Vertex *Graph_findByValue(Graph *g, void *value, int (*cmp)(void*, void*)) {
    Vertex *v = NULL;
    
    if (g) {
        v = g->first;
        
        while (v) {
            if (cmp(v->value, value) == 0)
                return v;
            v = v->next;
        }
    }
    
    return NULL;
}

static Vertex *notVisited(Edge *edge) {
    Edge *e = NULL;
    
    if (edge) {
        e = edge;
        
        while (e) {
            if (e->head->visited == 0)
                return e->head;
            e = e->next;
        }
    }
    
    return NULL;
}

static void dfs(Vertex *v, Vertex **path, int *count) {
    Vertex *k = NULL;
    
    if (v) {
        v->visited = 1;
        path[*count] = v;
        
        while (k = notVisited(v->first)) {
            *count += 1;
            dfs(k, path, count);
        }
    }
}

Vertex **Graph_dfs(Graph *g, void *value, int (*cmp)(void*,void*)) {
    Vertex ** path = NULL, *v = NULL;
    int i, count = 0;
    
    if(g && value && cmp) {
        v = g->first;
        while (v) {
            v->visited = 0;
            v = v->next;
        }
                
        v = Graph_findByValue(g, value, cmp);
        
        if (v) {
            path = calloc(g->n, sizeof(Vertex*));
            dfs(v, path, &count);
        }
    }
    
    return path;
}

Vertex **Graph_bfs(Graph *g, void *value, int (*cmp)(void*,void*)) {
    Vertex ** path = NULL, *v = NULL, *k;
    Queue *q = NULL;
    int count = 0;
    
    if(g && value && cmp) {
        v = g->first;
        while (v) {
            v->visited = 0;
            v = v->next;
        }
                
        v = Graph_findByValue(g, value, cmp);
        
        if (v) {
            path = calloc(g->n, sizeof(Vertex*));
            q = Queue_alloc(g->n);
            
            v->visited = 1;
            path[count++] = v;
            Queue_push(q, v);
            
            while (!Queue_isEmpty(q)) {
                v = Queue_begin(q);
                
                while (k = notVisited(v->first)) {
                    k->visited = 1;
                    path[count++] = k;
                    Queue_push(q, k);
                }
                
                Queue_pop(q);
            }
            
            Queue_free(q);
        }
    }
    
    return path;
}

typedef struct {
    Vertex *ant;
    int dist;
} Info;

int cmpInfo(void *a, void *b) {
    Vertex *v1 = (Vertex*) a;
    Vertex *v2 = (Vertex*) b;
    Info *inf1 = (Info*) v1->value;
    Info *inf2 = (Info*) v2->value;
        
    return inf2->dist - inf1->dist;
}

static Heap *init(Graph *g, int labelStart) {
    Heap *h = Heap_alloc(100, cmpInfo);
    Vertex *v = NULL;
    Info *new;
    int infinity = 9999;
    
    if (g) {
        v = g->first;
        
        while (v) {
            new = malloc(sizeof(Info));
            new->ant = NULL;
            
            if (v->label == labelStart)
                new->dist = 0;
            else
                new->dist = infinity++;
            
            v->value = new;
            
            Heap_insert(h, v);
            
            v = v->next;
        }
        
    }
    
    return h;
}

static void relax(Edge *e) {
    Info *i1, *i2;
    int *val;
    
    if (e) {
        if (e->tail->value && e->head->value) {
            i1 = (Info*) e->tail->value;
            i2 = (Info*) e->head->value;
            val = (int*) e->value;
            
            if (i1 && i2 && val) {
                if ((i1->dist + *val) < i2->dist) {
                    i2->dist = (i1->dist + *val);
                    i2->ant = e->tail;
                }
            }
            else 
                printf("error: i1 ou i2 ou val NULL\n");
        }
        else
            printf("error: e->tail->value ou e->head->value NULL\n");
    }
    else 
        printf("error: e NULL\n");
}

void Graph_dijkstra(Graph *g, int labelStart) {
    Heap *openVertices  = NULL;
    Vertex *v = NULL;
    Edge *e = NULL;
    
    openVertices = init(g, labelStart);
    
    if (openVertices) {
        
        while (openVertices->n) {
            v = Heap_remove(openVertices);
            
            if (v) {                    
                e = v->first;
                
                while (e) {
                    relax(e);
                    e = e->next;
                }
            }
        }
        
        Heap_free(openVertices);
    }
    else 
        printf("error: openVertices NULL\n");
}

int *val(int i) {
    int *v = malloc(sizeof(int));
    *v = i;
    return v;
}

int main() {
    Graph *g = Graph_alloc();
    int i, n;
    Vertex *v, *path[100];
    Info *inf;
    
    for (i=0; i<14; i++)
        Graph_insertVertex(g, NULL);

    Graph_insertEdge(g,  0,  4, val(8));
    Graph_insertEdge(g,  1,  0, val(6));
    Graph_insertEdge(g,  1,  2, val(5));
    Graph_insertEdge(g,  1,  3, val(2));
    Graph_insertEdge(g,  2,  6, val(2));
    Graph_insertEdge(g,  3,  5, val(2));
    Graph_insertEdge(g,  3,  6, val(3));
    Graph_insertEdge(g,  4,  7, val(3));
    Graph_insertEdge(g,  5,  4, val(5));
    Graph_insertEdge(g,  5,  8, val(2));
    Graph_insertEdge(g,  6, 10, val(4));
    Graph_insertEdge(g,  7,  8, val(1));
    Graph_insertEdge(g,  7, 11, val(5));
    Graph_insertEdge(g,  8,  9, val(4));
    Graph_insertEdge(g,  9, 12, val(9));
    Graph_insertEdge(g, 10,  9, val(2));
    Graph_insertEdge(g, 10, 13, val(2));
    Graph_insertEdge(g, 11, 12, val(6));
    Graph_insertEdge(g, 13, 12, val(3));    
    Graph_print(g, NULL);
    
    Graph_dijkstra(g, 1);
    
    printf("\nDistancias de 1 para todos os vertices\n");
    printf("Vertice Distancia Anterior\n");
    v = g->first;
    while (v) {
        inf = v->value;
        printf("%7d %9d ", v->label, inf->dist);
                    
        if (inf->ant)
            printf("%8d", inf->ant->label);
        
        printf("\n");
        v = v->next;
    }
    
    printf("\nCaminho entre 1 e 12\n");
    v = Graph_findByLabel(g, 12);
    n = 0;
    do {
		path[n++] = v;
		inf = v->value;
		v = inf->ant;
	}
	while (v);
		
	for (i=n-1; i>=0; i--)
		printf("(%d)->", path[i]->label);
	printf("\n");
        
    Graph_free(g);
    return 0;
}

/*
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
    printf("%s", a1->nome);
}

int main() {
    int i, j;
    Vertex *v, **path;
    Graph *g = Graph_alloc();
    Aluno alunos[5] = {
		{"Adao",{7.0,8.0,9.0}},
		{"Eva",{7.5,10.0,9.0}},
		{"Caim",{5.0,8.0,9.0}},
		{"Abel",{2.0,6.0,4.5}},
		{"Lilith",{8.0,9.0,10.0}}
	};
	Aluno *a;
    char nome[] = "Eva";
    
    Graph_insertVertex(g, &alunos[0]);
    Graph_insertVertex(g, &alunos[1]);
    Graph_insertVertex(g, &alunos[2]);
    Graph_insertVertex(g, &alunos[3]);
    Graph_insertVertex(g, &alunos[4]);
    
    Graph_insertEdge(g, 0, 1, NULL);
    Graph_insertEdge(g, 0, 3, NULL);
    Graph_insertEdge(g, 1, 3, NULL);
    Graph_insertEdge(g, 1, 2, NULL);
    //Graph_insertEdge(g, 1, 4, NULL);
    Graph_insertEdge(g, 2, 3, NULL);
    Graph_insertEdge(g, 4, 2, NULL);
    Graph_insertEdge(g, 0, 4, NULL);
    
    Graph_print(g, NULL);
    
   // Graph_removeVertex(g, 4);
    
    Graph_print(g, NULL);
    
    v = Graph_findByValue(g, nome, cmp);
    printf("label = %d, ", v->label);
    a = v->value;
    printf("%s %.1f %.1f %.1f\n", a->nome, a->nota[0], a->nota[1], a->nota[2]);
    
    Graph_print(g, print);
    
    printf("\nDFS\n");
    
    for (i=0; i < g->n; i++) {
        path = Graph_dfs(g, alunos[i].nome, cmp);
    
        if (path) {
            for (j=0; j < g->n; j++) {
                if (path[j] == NULL) { 
                    break;
                }
                else {
                    a = path[j]->value;
                    printf("(%s)->", a->nome);
                }
            }
            printf("\n");
        }
        
        free(path);
    }
    
    printf("\nBFS\n");
    
    for (i=0; i < g->n; i++) {
        path = Graph_bfs(g, alunos[i].nome, cmp);
    
        if (path) {
            for (j=0; j < g->n; j++) {
                if (path[j] == NULL) { 
                    break;
                }
                else {
                    a = path[j]->value;
                    printf("(%s)->", a->nome);
                }
            }
            printf("\n");
        }
        
        free(path);
    }
    
    Graph_free(g);

    return 0;
}
*/
