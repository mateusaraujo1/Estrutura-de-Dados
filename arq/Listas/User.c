#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"
#define tam 10

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

void User_insert(User *u, char login[], int password) {
	Node *new = NULL;
	if (u)
	{
		new = malloc(sizeof(Node));
		new -> login[tam] = login[tam];
		printf("\n%s\n", new->login);
        new -> password = password;
		new -> next = u -> first;
		u -> first = new;
		u -> lenght++;
	}
}

void List_print(User *u) {
	Node *n;
	if (u)
	{
		n = u -> first;

		while (n) {
			printf("login: %s || password: %d\n", n->login, n->password);
			n = n->next;
		} //quando n apontar pra NULL, acaba a repetição
		printf("\n");
	}
}

int List_remove(User* u, char login[tam]) {
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

int User_menu(User *u){
	int option, password;
	char login[tam];

	scanf("%d", &option);
	switch (option)
	{
	case 1:
		printf("novo login: ");
		scanf("%s", login);
		printf("nova password: ");
		scanf("%d", &password);
		User_insert(u, login, password);
		return 1;
	case 2:
		List_print(u);
		return 2;
	case 3:
		printf("login que será deletado: ");
		scanf("%s", login);
		List_remove(u, login);
		return 3;
	case 4:
		return 4;
	default:
		printf("\nDigite uma opção válida.\n");
		return 0;
	}
}

int main()
{
	User *u = User_alloc();
	int i;
	while (i != 4)
	{	
		printf("DIGITE O NÚMERO DA OPÇÃO DESEJADA\n");
		printf("(1) CRIAR USUÁRIO.\n");
		printf("(2) LISTAR USUÁRIOS.\n");
		printf("(3) EXCLUIR USUÁRIO.\n");
		printf("(4) SAIR DO PROGRAMA.\n");
		printf("\n: ");
		i = User_menu(u);
	}
	
	return 0;
}
