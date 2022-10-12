#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"

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
		printf("Estacionamento(%d):\n", Stack_length(s));
		
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

void Stack_pushCar(Stack *s, Carro *car, Queue *fila) {
	if (car->action == 'E' && !Stack_isFull(s))
		{
			printf("Carro %s entrou\n", car->placa);
			Stack_push(s, car);
		}
	else if (car->action == 'E' && Stack_isFull(s)) {
		printf("estacionamento cheio, carro %s entrou na fila\n", car->placa);
		Queue_push(fila, car);
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

		if (!Stack_isFull(s) && !Queue_isEmpty(fila))
		{
			car = Queue_pop(fila);
			printf("carro %s saiu da fila e entrou no estacionamento\n", car->placa);
			Stack_push(s, car);
		}
		
		Stack_free(aux);
		}
	
}

int main()
{
    char pula_linha;
    FILE *f = fopen("estacionamento.txt", "r");
    struct Carro car[50];
    int i = 0;

    if (f)
    {
        while (!feof(f))
        {
			if (fscanf(f, "%c%s%c", &car[i].action, car[i].placa, &pula_linha) == 3)
            	i++;	
        }
    }
    fclose(f);

	Stack *s = Stack_alloc(10);
	Queue *fila = Queue_alloc(20);
	for (int cont = 0; cont <= i; cont++) {//controla quanto total de linhas do arquivo que serão exibidas
		Stack_pushCar(s, &car[cont], fila);
		Stack_print(s, printCar);
		}

    return 0;
}