typedef struct BST BST;
typedef struct BST_node BST_node;

struct BST_node {
    void *item;
    BST_node *left, *right;
};

struct BST {
    BST_node *root;
    int n;
    int (*compar)(const void*,const void*);
};

BST  *BST_alloc(int (*compar)(const void*,const void*));
void  BST_free(BST *bst);
void  BST_insert(BST *bst, void *item);
void *BST_find(BST *bst, void *key);
void *BST_delete(BST *bst, void *key);

void  BST_print(BST_node *bst, void (*print)(void*));




