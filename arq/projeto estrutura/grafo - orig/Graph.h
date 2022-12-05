typedef struct Graph Graph;
typedef struct Vertex Vertex;
typedef struct Edge Edge;

struct Edge {
    int label;
    void *value;
	Vertex *tail;
	Vertex *head;
	Edge *next;
};

struct Vertex {
	int n;
	int label;
	int visited;
	void *value;
	Edge *first;
	Edge *last;
	Vertex *next;
};

struct Graph {
	int n;
	Vertex *first;
	Vertex *last;
};

Graph  *Graph_alloc();
void    Graph_free(Graph *g);	    
void    Graph_insertVertex(Graph *g, void *value);

void    Graph_insertEdge(Graph *g, int label1, int label2, void *value);	    

void    Graph_removeVertex(Graph *g, int label);
void    Graph_removeEdge(Graph *g,  int label1, int label2);
Vertex *Graph_findByLabel(Graph *g, int label);
Vertex *Graph_findByValue(Graph *g, void *value, int (*cmp)(void*, void*));
void    Graph_print(Graph *g, void (*print)(void *value));

Vertex **Graph_dfs(Graph *g, void *value, int (*cmp)(void*,void*));
Vertex **Graph_bfs(Graph *g, void *value, int (*cmp)(void*,void*));

void Graph_dijkstra(Graph *g, int labelStart);






