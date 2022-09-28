#include <stdlib.h>
#include <stdio.h>
#include "List.h"

typedef struct Node Node;

struct Node {
	void *value;
	Node *next;
};

struct List {
	int length;
	Node *first;
	Node *last;
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

void List_insert(List *l, void *value) {
	Node *new = NULL;
	if (l) {
		new = malloc(sizeof(Node));
		new->value = value;
		
		if (l->length == 0) {
			l->first = new;
			l->last = new;
		}
		else {
			l->last->next = new;
			l->last = new;
		}
		
		l->length++;
	}
}

void List_print(List *l, void (*print)(void*)) {
	Node *n;
	if (l && print) {
		n = l->first;
		
		while (n) {
			print(n->value);
			n = n->next;
		}
		printf("\n");
	}
}

void *List_find(List *l, void *value, int (*comp)(void*, void*)) {
	Node *n;
	if (l && value && comp) {
		n = l->first;
		while (n) {
			if (comp(n->value, value) == 0) {
				return n->value;
			}
			n = n->next;
		}
	}
	return NULL;
}

void *List_remove(List *l, void *value, int (*comp)(void*, void*)) {
	Node *n, *ant = NULL;
	
	if (l && value && comp) {
		n = l->first;
	
		while (n) {
			if (comp(n->value, value) == 0) {
				
				if (ant == NULL)
					l->first = n->next;
				else {
					if (n->next == NULL)
						l->last = ant;
					ant->next = n->next;
				}
				free(n);
				l->length--;
				break;
				
			}
			n = n->next;
		}
	}
	return NULL;
}
