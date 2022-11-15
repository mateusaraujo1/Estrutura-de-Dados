int evaluate(char *expression) {
	Stack *stack = Stack_alloc(strlen(expression));
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
