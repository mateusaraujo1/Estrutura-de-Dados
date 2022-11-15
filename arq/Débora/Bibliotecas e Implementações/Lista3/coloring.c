#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/Queue.h"
#define DIM 9

void show(int [DIM][DIM]);
void color(int);
void coloringArea(int [DIM][DIM], int, int, int, int);

int main() {
    int i, j, n;
    int img[DIM][DIM] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0, 0},
                         {0, 0, 0, 1, 1, 1, 0, 0, 0},
                         {0, 0, 1, 1, 1, 1, 1, 0, 0},
                         {0, 1, 1, 1, 1, 1, 1, 1, 0},
                         {0, 0, 2, 0, 0, 0, 2, 0, 0},
                         {0, 0, 2, 0, 0, 0, 2, 0, 0},
                         {0, 0, 2, 2, 2, 2, 2, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    while (1) {
        show(img);
        printf("\n\nNova cor (ou -1 para sair)? ");
        scanf("%d", &n);
        if (n<0) break;
        do {
            printf("Posição? ");
            scanf("%d %d", &i, &j);
        } while (i<0 || i>=DIM || j<0 || j>=DIM);
        coloringArea(img, i, j, n, 0);
    }

    return 0;
}

void color(int color) {
    switch (color) {
        case 0 : printf("\033[107m  \033[m"); break;
        case 1 : printf("\033[102m  \033[m"); break;
        case 2 : printf("\033[100m  \033[m"); break;
        case 3 : printf("\033[103m  \033[m"); break;
        case 4 : printf("\033[106m  \033[m"); break;
    }
}

void show(int img[DIM][DIM]) {
    int i, j;

    printf("   0 1 2 3 4 5 6 7 8 \n");
    for (i = 0; i < DIM; i++) {
        printf("%d ", i);
        for (j = 0; j < DIM; j++)
            color(img[i][j]);
        printf("\n");
    }
}

int *pixel(int i, int j) {
    int *p = (int*) malloc(sizeof(int));
    *p = i * DIM + j;
    return p;
}

void coloringArea(int img[DIM][DIM], int i, int j, int n, int edge) {
    Queue *q = Queue_create(DIM*DIM);
    int p;
    img[i][j] = n;
    Queue_push(q, pixel(i, j));

    while (!Queue_isEmpty(q)){
        p = *((int*)Queue_pop(q));
        i = p / DIM;
        j = p % DIM;

        if (img[i][j+1] != edge) {
            img[i][j+1] = n;
            Queue_push(q, pixel(i, j+1));
        }
        if (img[i+1][j] != edge) {
            img[i+1][j] = n;
            Queue_push(q, pixel(i+1, j));
        }
        if (i > 0)
            if (img[i-1][j] != edge) {
                img[i-1][j] = n;
                Queue_push(q, pixel(i-1, j));
            }
        if (j > 0)
            if (img[i][j-1] != edge) {
                img[i][j-1] = n;
                Queue_push(q, pixel(i, j-1));
            }
    }
    Queue_destroy(q);
}
