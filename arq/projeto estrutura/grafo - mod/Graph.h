typedef struct Graph  Graph;
typedef struct Vertex Vertex;

struct Vertex {
	int label; //ID do vértice, inicia do 0 e é também a sua posição no vetor de vértices
	int visited; //marca se foi ou não foi visitado
	void *value; //valor contido no vértice
};

struct Graph {
	int numV; //número de vértices
	int numA; //número de arestas
	int **adj; //matriz de adjacência
	Vertex *vtx; //vetor dos Vertex
};

Graph   *Graph_alloc(int V);
void    Graph_free(Graph *G);

void    Graph_insertEdge(Graph *G, int v, int w);
void    Graph_removeEdge(Graph *G, int v, int w);

Vertex  Graph_findByLabel(Graph *G, int label);
Vertex  Graph_findByValue(Graph *G, void *value, int (*cmp)(void*, void*));

void    Graph_print(Graph *G);

Vertex  *Graph_dfs(Graph *G, void *value, int (*cmp)(void*,void*));
Vertex  *Graph_bfs(Graph *G, void *value, int (*cmp)(void*,void*));

void 	Graph_valueVertex(Graph *G, int label, void *value); //adiciona ou edita o value à um vértice
void    Graph_printEdge(Graph *G);
void 	printName(void *a); //Função do main para imprimir o nome de um vértice