#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct BST
{
    void *value;
    BST *left;
    BST *right;
    int (*compar) (void*, void*);
};

BST *BST_alloc(int (*compar)(void*, void*)){
    BST *bst = NULL;

    if (compar)
    {
        bst = (BST*) malloc(sizeof(BST));
        bst->value = NULL;
        bst->left = NULL;
        bst->right = NULL;
        bst->compar = compar;
    }
}
void BST_free(BST *bst){
    if (bst)
    {
        BST_free(bst->left);
        BST_free(bst->right);
        free(bst);
    }
}
void BST_insert(BST *bst, void *value);
void *BST_search(BST *bst, void *value);
void *BST_remove(BST *bst, void *value);
void BST_print(BST *bst, void (*print)(void*));

int comp(void *a, void *b){
    int *n1 = (int*)a;
    int *n2 = (int*)b;
    return *n1 - *n2;
}

int main()
{
    int n[] = {12, 4, 6, 2, 76, 3};
    BST *bst = BST_alloc(comp);
    return 0;
}
