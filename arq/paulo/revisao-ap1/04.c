#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void a(Stack *s, int i) {
	Stack *saux = Stack_alloc(20);
	
	while(Stack_top(s) != i && !Stack_isEmpty(s))
		Stack_push(saux, Stack_pop(s));
	
	Stack_pop(s);
	
	while (Stack_length(saux) > 1)
		Stack_push(s, Stack_pop(saux));
	
	Stack_push(s, i);
	Stack_push(s, Stack_pop(saux));
	
	Stack_free(saux);
}

void b(Stack *s, int i) {
	Stack *saux = Stack_alloc(20);
	
	while(!Stack_isEmpty(s))
		Stack_push(saux, Stack_pop(s));
	
	Stack_push(s, i);
	
	while(!Stack_isEmpty(saux))
		if(Stack_top(saux) != i)
			Stack_push(s, Stack_pop(saux));
		else
			Stack_pop(saux);
	
	Stack_free(saux);
}

void c(Stack *s, int i, int n) {
	
}

int main() {
	Stack *s = Stack_alloc(20);
	Stack_push(s, 1);
	Stack_push(s, 2);
	Stack_push(s, 3);
	Stack_push(s, 4);
	Stack_push(s, 5);
	Stack_push(s, 6);
	Stack_print(s);
	
	a(s, 3);
	Stack_print(s);
	
	b(s, 5);
	Stack_print(s);
	
	Stack_free(s);
	return 0;
}
