typedef struct Queue Queue;

Queue *Queue_create(int length);
void   Queue_destroy(Queue *queue);
int    Queue_isEmpty(Queue *queue);
int    Queue_isFull(Queue *queue);
void   Queue_push(Queue *queue, void *element);
void  *Queue_pop(Queue *queue);
void  *Queue_begin(Queue *queue);
void  *Queue_end(Queue *queue);
int    Queue_getLength(Queue *queue);

void   Queue_print(Queue *queue, void (*print)(void *));