#include <stdio.h>
#include <string.h>
#include "avl.h"

int comparInt(const void *a, const void *b) {
    int *n1 = (int*)a;
    int *n2 = (int*)b;
    return *n1 - *n2;
}

int *AVL_height(AVL *t, void *key_item) {
    int *height = 0;
    int (*compar)(const void *, const void *);
    int cmp_result;
    AVL_node *p, *next_p;

    if ((next_p = t->root)) {
        compar = t->compar;
        do {
            p = next_p;
            cmp_result = compar(key_item, p->item);
            if (cmp_result < 0) {
                next_p = p->left;
                height += 1;
            }
            else if (cmp_result > 0) {
                next_p = p->right;
                height += 1;
            }
            else {
                /* Item found. */
                return height;
            }
        } while (next_p);
    }
    return NULL;
}

void printAVL(AVL *t) {
    int height = 0;
    AVL_print(t, t->root, height);
}

void printSpace(int cont) {
    if (cont)
        for (int i = 0; i < cont; i++)
        {
            printf("--");
        }
}

void printTreeInt(AVL_node *tree) {
    int *n;
    if (tree) {
        n = (int*) tree->item;
        printf("(%d ", *n);
        printTreeInt(tree->left);
        printTreeInt(tree->right);
        printf(") ");
    }
    else
		printf("~ ");
}

void AVL_print(AVL *t, AVL_node *node, int height) {
    printf("\n> ");
    int *n;
    if (node) {
        n = (int*) node->item;
        height = (int) AVL_height(t, node->item);
        printSpace(height);
        printf("%d", *n);
        AVL_print(t, node->left, height);
        AVL_print(t, node->right, height);
    }
    else {
        height += 4;
        printSpace(height);
		printf("NULL");
    }
}

/**
 * gcc AVL.c avl-exemplo-int.c -c && gcc AVL.o avl-exemplo-int.o && a
 * */
int main() {
    int num[] = {3, 7, 12, 13, 21, 16};

    AVL *treeInt = AVL_alloc( comparInt );

    AVL_insert(treeInt, &num[0]);
    AVL_insert(treeInt, &num[1]);
    AVL_insert(treeInt, &num[2]);
    //AVL_insert(treeInt, &num[4]);
    AVL_insert(treeInt, &num[3]);
    AVL_insert(treeInt, &num[4]);
    AVL_insert(treeInt, &num[5]);

    printTreeInt(treeInt->root);
    printf("\n");
    printAVL(treeInt);
    printf("\n");
    printf("%d", AVL_height(treeInt, &num[5]));
    /*
    int n = 11;
    AVL_delete(treeInt, &n);
    
    printTreeInt(treeInt->root);
    printf("\n");

    AVL_delete_min(treeInt);
    printTreeInt(treeInt->root);
    printf("\n");
    */

   AVL_free(treeInt);

    return 0;
}