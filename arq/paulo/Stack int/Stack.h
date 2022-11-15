typedef struct Stack Stack;

Stack *Stack_alloc(int size);
void   Stack_free(Stack *stack);
int    Stack_isEmpty(Stack *stack);
int    Stack_isFull(Stack *stack);
void   Stack_push(Stack *stack, int element);
int    Stack_pop(Stack *stack);
int    Stack_top(Stack *stack);
int    Stack_length(Stack *s);
void   Stack_print(Stack *s);
