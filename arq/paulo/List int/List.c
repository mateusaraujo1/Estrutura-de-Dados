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

void List_insert(List *l, int value) {
	Node *new = NULL;
	if (l) {
		new = malloc(sizeof(Node));
		new->value = value;
		new->next = NULL;
		
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

List *List_qsort(List *l) {
	List *a = NULL, *b = NULL;
	Node *n = NULL, *pivot = NULL;
	
	if (l) {
		
		if (l->length < 2) {
			return l;
		}
		else {
			a = List_alloc();
			b = List_alloc();
			pivot = l->first;
			
			n = pivot->next;
			while (n) {
				if (n->value < pivot->value)
					List_insert(a, n->value);
				else 
					List_insert(b, n->value);
				
				n = n->next;
			}
			
			a = List_qsort(a);
			b = List_qsort(b);
			
			List_insert(a, pivot->value);
			
			
			n = b->first;
			while (n) {
				List_insert(a, n->value);
				n = n->next;
			}
			
			List_free(b); 			
			List_free(l);
			
			return a;
		}
	}
}

int main() {
	List *l = List_alloc();
	
	List_insert(l, 9);
	List_insert(l, 66);
	List_insert(l, 3);
	List_insert(l, 19);
	List_insert(l, 12);
	List_insert(l, 8);	
	List_insert(l, 45);	
	List_insert(l, -27);	
	List_insert(l, 12);	
	List_print(l);
	
	l = List_qsort(l);
	List_print(l);
	
	List_insertSorted(l, 35);
	List_insertSorted(l, 0);
	
	List_print(l);
	List_free(l);
	
	return 0;
}
