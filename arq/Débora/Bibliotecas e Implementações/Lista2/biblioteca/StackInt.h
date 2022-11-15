typedef struct StackInt StackInt;

StackInt *StackInt_create(int size);
void      StackInt_destroy(StackInt *stack);
int       StackInt_isEmpty(StackInt *stack);
int       StackInt_isFull(StackInt *stack);
void      StackInt_push(StackInt *stack, int element);
int       StackInt_pop(StackInt *stack);
int       StackInt_top(StackInt *stack);
