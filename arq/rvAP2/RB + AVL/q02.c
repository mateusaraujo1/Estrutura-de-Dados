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

    //falta mostrar a altura

    return 0;
}
