#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct Node Node;

struct Node {
	int value;
	Node *next;
};

struct List {
	int lenght;
	Node *first;
}; //cabeça da lista

List *List_alloc() {
	List *l = malloc(sizeof(List));
	if (l)
	{
		l -> lenght = 0;
		l -> first = NULL;
		// ->acessando membros da struct de ponteiro
	}
}
void List_free(List *l) {
	Node *n, *aux;
	if (l)
	{
		n = l->first;
		while (n) {
			aux = n->next;
			free(n);
			n = aux;
		}
		free(l);
	}
}
void List_insert(List* l, int value) {
	Node *new = NULL;
	if (l)
	{
		new = malloc(sizeof(Node));
		new -> value = value;
		new -> next = l -> first;
		l -> first = new;
		l -> lenght++;
	}
}
int List_remove(List* l, int value) {
	Node *n, *ant = NULL;
	if (l)
	{
		n = l->first;
		while (n) {
			if (n->value == value)
			{
				if (ant == NULL)
					l->first = n->next;
				else 
					ant->next = n -> next;

				free(n);
				l->lenght--;
				break;
			}
			ant = n;
			n = n->next;
		}
	}
}
int List_getLength(List *l) {
	if (l)
	{
		return l->lenght;
	}
	return 0;
}
void List_print(List *l) {
	Node *n;
	if (l)
	{
		n = l -> first;

		while (n) {
			printf("%d ", n->value);
			n = n->next;
		} //quando n apontar pra NULL, acaba a repetição
		printf("\n");
	}
}

int main() {
	List *l = List_alloc();
	List_insert(l, 3);
	List_insert(l, 9);
	List_insert(l, 18);
	List_insert(l, 4);
	List_insert(l, 1);
	List_print(l);
	List_remove(l, 9);
	List_print(l);
	List_remove(l, 1);
	List_print(l);
	List_free(l);
	return 0;
}