#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef struct { 
	int n, val[4];
} Posicao;

void insert(Queue *q, int n) {
	Posicao *new, *aux;
	if (q) {
		if (Queue_isEmpty(q)) {
			new = malloc(sizeof(Posicao));
			new->n = 0;
			
			new->val[new->n] = n;
			new->n++;
			
			Queue_push(q, new);
		}
		else {
			aux = Queue_end(q);
			if (aux->n < 4) {
				aux->val[aux->n] = n;
				aux->n++;
			}
			else {
				new = malloc(sizeof(Posicao));
				new->n = 0;
				
				new->val[new->n] = n;
				new->n++;
				
				Queue_push(q, new);
			}
		}
	}
}

void print(void *a) {
	Posicao *p = (Posicao*)a;
	printf("[%d] (%d,%d,%d,%d)", p->n, p->val[0],
										p->val[1],
										p->val[2],
										p->val[3]);
}

int main() {
	Queue *q = Queue_alloc(5);
	int i;
	for (i=0; i<17; i++)
		insert(q, i);
	
	Queue_print(q, print);
	return 0;
}
