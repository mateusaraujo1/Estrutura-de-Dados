#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
#define N 11

int LAB[N][N];

void show() {
	int i, j;
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++)
			switch(LAB[i][j]) {
				case 0:
				case 4:
					printf("  ");
					break;
				case 1:
					printf("\u2591\u2591");
					break;
				case 2:
					printf("\u2615");
					break;
				case 3:
					printf("\u26c4");
					break;
			}
		printf("\n");
	}
}

typedef struct {
	int x, y;
} Coord;

Coord *Coord_alloc(int x, int y) {
	Coord *c = malloc(sizeof(Coord));
	if (c) {
		c->x = x;
		c->y = y;
	}
	return c;
}

Coord *next(Coord *cur) {
	// CIMA
	if (LAB[cur->x-1][cur->y] == 0 ||
		LAB[cur->x-1][cur->y] == 2)
		return Coord_alloc(cur->x-1, cur->y);
	
	// BAIXO
	if (LAB[cur->x+1][cur->y] == 0 ||
		LAB[cur->x+1][cur->y] == 2)
		return Coord_alloc(cur->x+1, cur->y);
	
	// DIREITA
	if (LAB[cur->x][cur->y+1] == 0 ||
		LAB[cur->x][cur->y+1] == 2)
		return Coord_alloc(cur->x, cur->y+1);
	
	// ESQUERDA
	if (LAB[cur->x][cur->y-1] == 0 ||
		LAB[cur->x][cur->y-1] == 2)
		return Coord_alloc(cur->x, cur->y-1);
		
	return NULL;
}

void mark(Coord *c) {
	if (c)
		LAB[c->x][c->y] = 4;
}

void move(Coord *c) {
	if (c) {
		LAB[c->x][c->y] = 3;
	}
}

int main() {
	FILE *f = fopen("labirinto.txt", "r");
	int i, j;
	Coord *cur, *new;
	Stack *s = Stack_alloc(N*N);
	
	if (f) {
		for (i=0; i<N; i++)
			for (j=0; j<N; j++)
				fscanf(f, "%d", &LAB[i][j]);
		fclose(f);
	}
	
	srand(time(NULL));
	
	do {
		i = rand() % N;
		j = rand() % N;
	}
	while (LAB[i][j]);
	
	LAB[i][j] = 3;
	cur = Coord_alloc(i, j);
	
	while (1) {
		system("clear");
		show();
		
		new = next(cur);
		if (new)
			Stack_push(s, cur);
		else
			new = Stack_pop(s);
		
		mark(cur);
		
		if(LAB[new->x][new->y] == 2)
			break;
		
		move(new);
		cur = new;
		getchar();
	}
	
	show();
	return 0;
}
