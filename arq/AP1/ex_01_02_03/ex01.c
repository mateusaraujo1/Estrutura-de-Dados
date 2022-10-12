#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main() {
	List *l = List_alloc();

	List_insert(l, 9);
	List_insert(l, 6);
	List_insert(l, 9);
	List_insert(l, 9);
	List_insert(l, 1);
	List_insert(l, 32);
	List_insert(l, 1);
	List_insert(l, 6);
	List_insert(l, 9);
	List_print(l);

    List_unique(l, 9);
	List_print(l);
	
	List_free(l);
	
	return 0;
}