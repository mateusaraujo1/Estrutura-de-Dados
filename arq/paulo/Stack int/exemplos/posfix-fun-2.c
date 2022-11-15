char *posfix(char *in) {
	Stack *s = Stack_alloc(SIZE);
	char *out = malloc(SIZE);
	int i, j;
	for (i = 0; in[i]; i++) {
		if (in[i] == '(') Stack_push(s, in[i]);
		else if (isdigit(in[i])) out[j++] = in[i];
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
