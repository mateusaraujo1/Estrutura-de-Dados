typedef struct List List;

List *List_alloc();
void  List_free(List *l);
void  List_insert(List *l, int value);
void  List_remove(List *l, int value);
int   List_getLenght(List *l);
void  List_print(List *l);
void  List_insertSorted(List *l, int value);
List *List_qsort(List *l);
void List_unique(List *l, int value);
int List_removeMax(List *l);
void List_insertAfter(List *l, int n1, int n2);