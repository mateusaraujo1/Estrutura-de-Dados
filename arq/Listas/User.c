#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"
#define tam 30

typedef struct Node Node;

struct Node {
    char login[tam];
	int password;
	Node *next;
};

//HEAD da lista
struct User {
	int lenght;
	Node *first;
};

User *User_alloc() {
    User *u = malloc(sizeof(User));
    if (u)
    {
        u -> lenght = 0;
		u -> first = NULL;
    }
}

void User_free(User *u) {
	Node *n, *aux;
	if (u)
	{
		n = u->first;
		while (n) {
			aux = n->next;
			free(n);
			n = aux;
		}
		free(u);
	}
}

void User_insert(User* u, char login[tam], int password) {
	Node *new = NULL;
	if (u)
	{
		new = malloc(sizeof(Node));
		new -> login[tam] = login[tam];
        new -> password = password;
		new -> next = u -> first;
		u -> first = new;
		u -> lenght++;
	}
}

//LISTAR

int List_remove(User* u, char login[tam], int password) {
	Node *n, *ant = NULL;
	if (u)
	{
		n = u->first;
		while (n) {
			if (strcmp(n->login, login) == 0)
			{
				if (ant == NULL)
					u->first = n->next;
				else 
					ant->next = n -> next;

				free(n);
				u->lenght--;
				break;
			}
			ant = n;
			n = n->next;
		}
	}
}