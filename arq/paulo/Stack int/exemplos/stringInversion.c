#include <stdio.h>
#include "Stack.h"

int main() {
	char str[20], i;
	Stack *s = Stack_alloc(20);
	
	printf("String: ");
	scanf("%[^\n]", str);
	for (i = 0; str[i]; i++)
		Stack_push(s, str[i]);
	
	printf("String invertida: ");
	while (!Stack_isEmpty(s))
		printf("%c", Stack_pop(s));
	printf("\n");
	Stack_free(s);
	return 0;
}
