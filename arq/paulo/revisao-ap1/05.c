#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
	Stack *s = Stack_alloc(1000);
	int n = 3960, d;
	
	for (d=2; n>1; ) {
		if (n%d == 0) {
			Stack_push(s, d);
			n = n/d;
		}
		else
			d++;
	}
	
	while (!Stack_isEmpty(s)) {
		printf("%d * ", Stack_pop(s));
	}
	printf("\n");
	
	Stack_free(s);
	return 0;
}
