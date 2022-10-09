#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Stack.h"
#define SIZE 256

char *posfix(char *in) {
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
