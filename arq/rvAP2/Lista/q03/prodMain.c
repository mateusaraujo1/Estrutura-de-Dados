#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

int comparProd(const void *a, const void *b) {
    Produto *p1 = (Produto*)a;
    Produto *p2 = (Produto*)b;
    return strcmp(p1->nome, p2->nome);
}

void printfTreeProd(AVL_node *tree) {
    Produto *p; 
    if (tree) {
        p = (Produto*)tree->item;
        
        printfTreeProd(tree->left);
        printf("%-20s %-15s %-10d %-5.2f\n", p->nome, p->marca, p->codigo, p->preco);
        printfTreeProd(tree->right);
    }
}

// gcc AVL.c prodMain.c -c && gcc AVL.o prodMain.o && a

int main()
{
    char pula_linha;
    FILE *f = fopen("produtos.txt", "r");
    AVL *tree = AVL_alloc(comparProd);
    Produto p[15];

    if (f)
    {
        for (int i = 0; i < 15; i++) //se quiser só os 8 primeiros, ponho i < 8, simples
        {
			if (fscanf(f, "%s%s%d%f%c", p[i].nome, p[i].marca, &p[i].codigo, &p[i].preco, &pula_linha) == 5) {
                AVL_insert(tree, &p[i]);
                //printf("%-20s %-15s %-10d %-5.2f\n", p[i].nome, p[i].marca, p[i].codigo, p[i].preco);
            }
        }
    }

    printfTreeProd(tree->root);
    //depois é só mudar a função de comparação pra ordenar pela marca ao invés do nome, só mudar o nome pela a marca, aí termina a questão

    fclose(f);
    
    return 0;
}