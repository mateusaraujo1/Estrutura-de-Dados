#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"

typedef struct {
	char login[20];
	int senha;
} Usuario;

int menu() {
	int op;
	printf("1 cadastrar\n2 listar\n3 excluir\n4 sair\n:");
	scanf("%d", &op);
	return op;
}

void print(void *a) {
	Usuario *u = (Usuario*)a;
	printf("%10s %8d\n", u->login, u->senha);
}

int cmp(void *a, void *b) {
	Usuario *u = (Usuario*)a;
	char *login = (char*)b;
	return strcmp(u->login, login);
}

void cadastrar(List *l) {
	Usuario *u = malloc(sizeof(Usuario));
	if (l && u) {
		
		printf("Cadastro\n login: ");
		scanf("%s", u->login);
		do {
			printf(" senha: ");
			scanf("%d", &u->senha);
			if (u->senha < 10000000 || u->senha > 99999999)
				printf("erro: a senha deve ter 8 digitos.\n");
		}
		while (u->senha < 10000000 || u->senha > 99999999);
		
		List_insert(l, u);
		system("clear");
		printf("Usuario cadastrado com sucesso\n");
	}
}

void listar(List *l) {
	system("clear");
	printf("%10s %8s\n", "Login", "Senha");
	List_print(l, print);
}

void excluir(List *l) {
	char login[20];
	Usuario *u = NULL;
	
	printf(" login: ");
	scanf("%s", login);
	
	u = List_remove(l, login, cmp);
	
	system("clear");
	if (u)
		printf("Usuario removido com sucesso\n");
	else
		printf("Usuario nao encontrado\n");
}

int main() {
	List *usuarios = List_alloc();
	int op = 0;
	while (1) {
		op = menu();
		if (op == 1) cadastrar(usuarios);
		else if (op == 2) listar(usuarios);
		else if (op == 3) excluir(usuarios);
		else if (op == 4) break;
		else print("erro: opção inválida.\n");
	}
}




