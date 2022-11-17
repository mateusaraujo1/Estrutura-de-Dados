#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"
#include "RB.h"
#define tam 1000

int comparInt(const void *a, const void *b) {
    int *n1 = (int*)a;
    int *n2 = (int*)b;
    return *n1 - *n2;
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

/*
     Função para calcular a altura de uma árvore binária
*/

int altura_AVL(AVL_node *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura_AVL(raiz->left);
        int dir = altura_AVL(raiz->right);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int altura_RB(RB_node *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura_RB(raiz->left);
        int dir = altura_RB(raiz->right);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

void printVec(int *vec) {
    printf("[");
    for (int i = 0; i < tam; i++)
        printf("%03d, ", vec[i]);
    printf("]\n");
}

void preencheAVL(AVL *tree, int *vec) {
    for (int i = 0; i < tam; i++)
        AVL_insert(tree, &vec[i]);
}

void preencheRB(RB *tree, int *vec) {
    for (int i = 0; i < tam; i++)
        RB_insert(tree, &vec[i]);
}

// gcc AVL.c RB.c q02.c -c && gcc AVL.o RB.o q02.o && a

int main()
{
    int *vec = NULL;
    AVL *treeAVL = AVL_alloc(comparInt);
    RB *treeRB = RB_alloc(comparInt);
    vec = malloc(sizeof(int)*1000);
    srand(time(NULL));

    for (int i = 0; i < tam; i++)
        vec[i] = rand() % 1000;

    //printVec(vec);
    preencheAVL(treeAVL, vec);
    preencheRB(treeRB, vec);

    //RB_print(treeRB->root, print);
    //printTreeInt(treeAVL->root);

    printf("Altura AVL: %d\n", altura_AVL(treeAVL->root));
    printf("Altura RB: %d\n", altura_RB(treeRB->root));

    return 0;
}
