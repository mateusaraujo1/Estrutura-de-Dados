typedef struct Graph Graph;
typedef struct Vertex Vertex;
typedef struct Edge Edge;

struct Graph{
  int numberVertices;
  Vertex *first;
  int (*compar)(void *, void *);
};

struct Vertex{
  int numberLinks;
  void *value;
  Edge *first;
  Vertex *next;
};

struct Edge{
  Edge *next;
  Vertex *origin;
  Vertex *target;
};

Graph  *Graph_create(int (*compar)(void *, void *));
void    Graph_destroy(Graph *g);
void    Graph_insert(Graph *g, void *value);
void    Graph_link(Graph *g, void *origin, void *target);
void    Graph_delete(Graph *g, void *value);
void    Graph_print(Graph *g, void (*print)(void *));
int     Graph_numberVertex(Graph *g);

Vertex *Vertex_create(void *value);
void    Vertex_destroy(Vertex *v);
Vertex *Vertex_find(Graph *g, void *value);
int     Vertex_numberLinks(Graph *g, void *value);
int     Vertex_occasion(Graph *g, void *value);

Edge   *Edge_create();
void    Edge_destroy(Edge *e);
void    Edge_delete(Graph *g, void *value1, void *value2);
Edge   *Edge_find(Graph *g, void *value1, void *value2);
