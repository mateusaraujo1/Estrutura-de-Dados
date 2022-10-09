#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"

typedef struct {
	char nome[20];
	float IRA;
	int matricula;
} Aluno;

void print(void *x) {
	Aluno *a = (Aluno*)x;
	printf("[%s %.3f %d]\n", a->nome, a->IRA, a->matricula);
}

int cmpMat(void *x, void *y) {
	Aluno *a = (Aluno*)x;
	int *mat = (int*)y;
	return a->matricula - *mat;
}

int cmpNome(void *x, void *y) {
	Aluno *a = (Aluno*)x;
	char *nome = (char*)y;
	return strcmp(a->nome, nome);
}

int main() {
	List *l = List_alloc();
	Aluno a[] = {{"Astrogildo", 9.725, 111},
				 {"Vanderlucia", 7.500, 222},
				 {"Miraneide", 5.0, 333},
				 {"Bill", 1.2, 444}};
	
	int mat = 333;
	char *nome = "Bill";
	Aluno *aluno;
	
	List_insert(l, &a[0]);
	List_insert(l, &a[1]);
	List_insert(l, &a[2]);
	List_insert(l, &a[3]);
	
	List_print(l, print);

	aluno = List_find(l, &mat, cmpMat);
	print(aluno);
	
	aluno = List_find(l, nome, cmpNome);
	print(aluno);

	List_free(l);

	return 0;
}
