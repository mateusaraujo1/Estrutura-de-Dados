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
