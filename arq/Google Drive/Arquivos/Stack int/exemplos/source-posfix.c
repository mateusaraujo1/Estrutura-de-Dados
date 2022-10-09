#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Stack.h"
#define SIZE 256

char *posfix_simple(char *in) {
	Stack *s = Stack_alloc(SIZE);
	char *out = malloc(SIZE);
	int i, j;
	for (i = 0; in[i]; i++)
		if (isdigit(in[i]))
			out[j++] = in[i];
		else if (strchr("+*-/", in[i]))
			Stack_push(s, in[i]);
		else if (in[i] == ')')
			out[j++] = Stack_pop(s);
	out[j] = '\0';
	Stack_free(s);
	return out;
}

////////////////////////////////////////////////////////////////////////

int priority(char c) {
	switch (c) {
		case '(': return 0;    
		case '+': 
		case '-': return 1; 
		case '*': 
		case '/': return 2;
	}
	return -1;
}

char *posfix_priority(char *in) {
	Stack *s = Stack_alloc(SIZE);
	char *out = malloc(SIZE);
	int i, j;
	for (i = 0; in[i]; i++) {
		if (in[i] == '(') Stack_push(s, in[i]);
		if (isdigit(in[i]) ) out[j++] = in[i];
		else if (strchr("+*-/", in[i])) {
			while (!Stack_isEmpty(s) 
					&& priority(in[i]) <= priority(Stack_top(s)) )
				out[j++] = Stack_pop(s);
			Stack_push(s, in[i]);
		}
		else if (in[i] == ')') {
			while (Stack_top(s) != '(')
				out[j++] = Stack_pop(s);
			Stack_pop(s);
		}
	}
	while (!Stack_isEmpty(s))
		out[j++] = Stack_pop(s);
	out[j] = '\0';
	Stack_free(s);
	return out;
}

int evaluate(char *expression) {
	Stack *stack = Stack_alloc(SIZE);
	int i, x, y, z;
	for (i = 0; expression[i]; i++)
		if (isdigit(expression[i]))
			Stack_push(stack, expression[i] - '0');
		else {
			y = Stack_pop(stack);
			x = Stack_pop(stack);
			switch (expression[i]) {
				case '+': Stack_push(stack, x+y); break;
				case '-': Stack_push(stack, x-y); break;
				case '*': Stack_push(stack, x*y); break;
				case '/': Stack_push(stack, x/y); break;
			}
		}
	z = Stack_pop(stack);
	Stack_free(stack);
	return z;
}

////////////////////////////////////////////////////////////////////////

char *posfix_spaces(char *in) {
	Stack *s = Stack_alloc(SIZE);
	char     *out = (char *) malloc(SIZE * sizeof(char));
	int         i = 0, j = 0;
	for (i = 0; in[i]; i++) {
		if ( in[i] == '('   ) Stack_push(s, in[i]);
		if ( isdigit(in[i]) ) out[j++] = in[i];
		else if ( strchr("+*-/", in[i]) ) {
			out[j++] = ' ';
			while ( !Stack_isEmpty(s) 
					&& priority(in[i]) <= priority(Stack_top(s)) )
				out[j++] = Stack_pop(s);
			Stack_push(s, in[i]);
		}
		else if ( in[i] == ')' ) {
			while ( Stack_top(s) != '(' )
				out[j++] = Stack_pop(s);
			Stack_pop(s);
		}
	}
	while ( !Stack_isEmpty(s) )
		out[j++] = Stack_pop(s);
	out[j] = '\0';
	Stack_free(s);
	return out;
}

int evaluate(char *expression) {
	Stack *stack = Stack_alloc(SIZE);
	int i, j, x, y, z;
	char *subExp = (char*) malloc(strlen(expression));
	for (i = 0; expression[i]; i++) {
		if ( isdigit(expression[i]) ) {
			for (j = 0; isdigit(expression[i]); j++, i++)
				subExp[j] = expression[i];
			subExp[j] = '\0';
			Stack_push(stack, atoi(subExp));
		}
		if ( strchr("+-*/", expression[i]) ) {
			y = Stack_pop(stack);
			x = Stack_pop(stack);
			switch (expression[i]) {
				case '+': Stack_push(stack, x+y); break;
				case '-': Stack_push(stack, x-y); break;
				case '*': Stack_push(stack, x*y); break;
				case '/': Stack_push(stack, x/y); break;
			}
		}
	}
	z = Stack_pop(stack);
	Stack_free(stack); free(subExp);
	return z;
}

int main() {

    return 0;
}
