#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

struct Stack {
	int size;
	int top;
	int *elements;
};

Stack *Stack_alloc(int size){
	Stack *s = NULL;
	
	if (size > 0) {
		s = malloc(sizeof(Stack));
		
		if (s) {
			s->size = size;
			s->top = -1;
			s->elements = calloc(size, sizeof(int));
			
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

void Stack_push(Stack *s, int element){
	if (s && !Stack_isFull(s)) {
		s->top++;
		s->elements[s->top] = element;
	}
}

int Stack_pop(Stack *s){ 
	int el = 0;
	if (s) {
		if (Stack_length(s) > 0) {
			el = s->elements[s->top];
			s->elements[s->top] = 0;
			s->top--;
		}
	}
	return el;
}

int Stack_top(Stack *s){ 
	if (s)
		if (Stack_length(s) > 0)
			return s->elements[s->top];
	return 0;
}

int Stack_length(Stack *s) {
	if (s)
		return s->top + 1;
	return 0;
}

void Stack_print(Stack *s) {
	int i;
	if (s) {
		printf("Stack(%d):\n", Stack_length(s));
		
		for (i=s->top; i>=0; i--)
			printf(" %d\n", s->elements[i]);
	}
}

/*
int main() {
	Stack *s = Stack_alloc(20);
	Stack_push(s, 7);
	Stack_push(s, 3);
	Stack_push(s, 19);
	Stack_push(s, 21);
	Stack_push(s, 2);
	Stack_push(s, 8);
	
	printf("top = %d\n", Stack_top(s));
	Stack_print(s);
	
	printf("pop = %d\n", Stack_pop(s));
	Stack_print(s);
	
	Stack_free(s);
	return 0;
}
*/




