#include <stdlib.h>
#include <stdio.h>
#include "List.h"

typedef struct Node Node;

struct Node {
	int value;
	Node *next;
};

struct List {
	int length;
	Node *first;
};

List *List_alloc() {
	List *l = malloc(sizeof(List));
	if (l) {
		l->length = 0;
		l->first = NULL;
	}
	return l;
}

void List_free(List *l) {
	Node *n, *aux;
	if (l) {
		n = l->first;
		while (n) {
			aux = n->next;
			free(n);
			n = aux;
		}
		free(l);
	}
}

void List_insert(List *l, int value) {
	Node *new = NULL;
	if (l) {
		new = malloc(sizeof(Node));
		new->value = value;
		new->next = NULL;
		
		new->next = l->first;
		l->first = new;
		l->length++;
	}
}

void List_remove(List *l, int value) {
	Node *n, *ant = NULL;
	if (l) {
		n = l->first;
		
		while (n) {
			if (n->value == value) {
				if (ant == NULL)
					l->first = n->next;
				else
					ant->next = n->next;
				free(n);
				l->length--;
				break;
			}
			ant = n;
			n = n->next;
		}
	}
}

int List_getLenght(List *l) {
	if (l) {
		return l->length;
	}
	return 0;
}

void List_print(List *l) {
	Node *n;
	if (l) {
		n = l->first;
		
		while (n) {
			printf("%d ", n->value);
			n = n->next;
		}
		printf("\n");
	}
}


void List_insertSorted(List *l, int value) {
	Node *new = NULL, *n, *ant = NULL;
	if (l) {
		new = malloc(sizeof(Node));
		new->value = value;
		new->next = NULL;
		
		n = l->first;
		while (n) {
			if (value <= n->value) {
				if (ant == NULL) {
					new->next = l->first;
					l->first = new;
				}
				else {
					new->next = n;
					ant->next = new;
				}
				break;
			}
			ant = n;
			n = n->next;
		}
		
		if (l->length == 0)
			l->first = new;
		else
			ant->next = new;
			
		l->length++;
	}
}

int main() {
	List *l = List_alloc();
	
	List_insertSorted(l, 3);
	List_insertSorted(l, 9);
	List_insertSorted(l, 12);
	List_insertSorted(l, 8);	
	List_print(l);
	
	List_free(l);	
	return 0;
}
