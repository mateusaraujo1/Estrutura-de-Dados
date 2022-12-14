#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main() {
	List *l = List_alloc();

	List_insert(l, 19);
	List_insert(l, 6);
	List_insert(l, 3);
	List_insert(l, 9);
	List_insert(l, 8);	
	List_insert(l, 2);	
	List_insert(l, 1);
	List_print(l);

	List_insertAfter(l, 3, 10);
	List_print(l);

	List_free(l);
	
	return 0;
}