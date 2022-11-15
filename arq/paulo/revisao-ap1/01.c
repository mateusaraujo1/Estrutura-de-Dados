#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main() {
	List *l = List_alloc();
	List_insert(l, 1); 
	List_insert(l, 3); 
	List_insert(l, 5); 
	List_insert(l, 7); 
	List_insert(l, 9);
	List_print(l);
	printf("length = %d\n", List_count(l)); 
	List_free(l);
	return 0;
}
