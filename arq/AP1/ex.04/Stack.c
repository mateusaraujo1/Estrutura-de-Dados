#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"

struct Stack {
	int size;
	int top;
	void **elements;
};

struct Carro {
	char action;
	char placa[10];
};

Stack *Stack_alloc(int size){
	Stack *s = NULL;
	
	if (size > 0) {
		s = malloc(sizeof(Stack));
		
		if (s) {
			s->size = size;
			s->top = -1;
			s->elements = calloc(size, sizeof(void*));
			
			if (s->elements == NULL) {
				free(s);
				s = NULL;
			}
		}
	}
	
	return s;
}

void Stack_free(Stack *s){
	if (s) {
		free(s->elements);
		free(s);
	}
}

int Stack_isEmpty(Stack *s){ 
	if (s)
		return s->top == -1;
}

int Stack_isFull(Stack *s){ 
	if (s)
		return s->top == (s->size - 1);
}

void Stack_push(Stack *s, void *element){
	if (s && !Stack_isFull(s)) {
		s->top++;
		s->elements[s->top] = element;
	}
}

void *Stack_pop(Stack *s){ 
	void *el = NULL;
	if (s) {
		el = s->elements[s->top];
		s->elements[s->top] = NULL;
		s->top--;
	}
	return el;
}

void *Stack_top(Stack *s){ 
	if (s)
		return s->elements[s->top];
	
	return NULL;
}

int Stack_length(Stack *s) {
	if (s)
		return s->top + 1;
	
	return 0;
}

void Stack_print(Stack *s, void (*print)(void*)) {
	int i;
	if (s) {
		printf("Stack(%d):\n", Stack_length(s));
		
		for (i=s->top; i>=0; i--) {
			print(s->elements[i]);
			printf("\n");
		}
	}
}

void printCar(void *a) {
	Carro *c = (Carro*)a;
	printf("%s", c->placa);
}

/*
typedef struct {
	char nome[20];
	int mundiais;
} Time;

void printTime(void *a) {
	Time *t = (Time*)a;
	printf("%s %d", t->nome, t->mundiais);
}

int main() {
	Time times[] = {{"Sao Paulo",3},
					{"Corinthians",2},
					{"Palmeiras",0},
					{"Flamengo",1}};
	Stack *s = Stack_alloc(20);
	
	Stack_push(s, &times[0]);
	Stack_push(s, &times[1]);
	Stack_push(s, &times[2]);
	Stack_push(s, &times[3]);
	
	Stack_print(s, printTime);
	
	Stack_free(s);
	return 0;
}
*/

void Stack_pushCar(Stack *s, Carro *car) {
	if (car->action == 'E')
		{
			printf("Carro %s entrou\n", car->placa);
			Stack_push(s, car);
		}
	else
		{
		printf("Carro %s saiu\n", car->placa);
		Stack *aux = Stack_alloc(20);
		while (!Stack_isEmpty(s))
		{
			Carro *auxCar;
			auxCar = Stack_pop(s);

			if ((strcmp(auxCar->placa, car->placa)) != 0)
			{
				Stack_push(aux, auxCar);
			} 
			else 
			{
				while (!Stack_isEmpty(aux))
				{
					Stack_push(s, Stack_pop(aux));
				}
				break;
			}
		}

		if (Stack_isEmpty(s)) {
			printf("...mas ele ja tinha saido\n");
			while (!Stack_isEmpty(aux))
				{
					Stack_push(s, Stack_pop(aux));
				}
		}
		Stack_free(aux);
		}
	
}

int main()
{
    char pula_linha;
    FILE *f = fopen("estacionamento.txt", "r");
    struct Carro car[50];

    if (f)
    {
        int i = 0;
        while (!feof(f))
        {
            fscanf(f, "%c%s%c", &car[i].action, car[i].placa, &pula_linha);
            //printf("%c:%s%c", car[i].action, car[i].placa, pula_linha);
            i++;
        }
    }
    fclose(f);

	Stack *s = Stack_alloc(20);
	for (int i = 0; i < 28; i++) //controla quantas linhas do arquivo serão exibidas
		Stack_pushCar(s, &car[i]);

	Stack_print(s, printCar);
    return 0;
}