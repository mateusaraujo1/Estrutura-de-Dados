typedef struct Stack Stack;
typedef struct Carro Carro;

Stack *Stack_alloc(int size);
void   Stack_free(Stack *stack);
int    Stack_isEmpty(Stack *stack);
int    Stack_isFull(Stack *stack);
void   Stack_push(Stack *stack, void *element);
void  *Stack_pop(Stack *stack);
void  *Stack_top(Stack *stack);
int    Stack_length(Stack *s);
void   Stack_print(Stack *s, void (*print)(void*));