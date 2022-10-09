#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
	int number = 0;
	Stack *s = Stack_alloc(20);
	
	printf("Decimal number: ");
	scanf("%d", &number);
	do {
		Stack_push(s, number % 2);
		number /= 2;
	} while (number != 0);
	
	printf("Binary number: ");
	while (!Stack_isEmpty(s))
		printf("%d", Stack_pop(s));
	printf("\n");
	Stack_free(s);
	return 0;
}
