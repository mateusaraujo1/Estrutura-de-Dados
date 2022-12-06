#define vert int

typedef struct Graph *Graph;
typedef struct Vertex Vertex;

struct Vertex {
	int label;
	void *value;
};

struct Graph {
	int numV;
	int numA;
	int **adj; //matriz de adjacência
	Vertex *vtx; //vetor dos Vertex
};

Graph   Graph_alloc(int V);
//void    Graph_free(Graph *g);

void    Graph_insertEdge(Graph G, vert v, vert w);
void    Graph_removeEdge(Graph G, vert v, vert w);

//Vertex *Graph_findByLabel(Graph *g, int label);
//Vertex *Graph_findByValue(Graph *g, void *value, int (*cmp)(void*, void*));
void    Graph_print(Graph G);

//Vertex **Graph_dfs(Graph *g, void *value, int (*cmp)(void*,void*));
//Vertex **Graph_bfs(Graph *g, void *value, int (*cmp)(void*,void*));

//funções adicionais
void 	Graph_valueVertex(Graph G, int label, void *value);
void    Graph_printEdge(Graph G);