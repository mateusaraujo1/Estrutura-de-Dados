#include <stdlib.h>
#include "Stack.h"

struct Stack
{
    int size;
    int top;
    int *elements;
};

Stack *Stack_alloc(int size){
    Stack *s = NULL;
    s = (Stack*) malloc(sizeof(Stack));

    if (s != NULL) {
        s->top = -1;
        s->size = size;
        s->elements = malloc(size * sizeof(int));

        if (s->elements == NULL) {
            free(s);
            return NULL;
        } 
    }
    return s;
}

void Stack_free(Stack *s){
    if (s != NULL) {
        free(s->elements);
        free(s);
    }
}

int Stack_isEmpty(Stack *s){
    if (s != NULL)
    {
        return s->top == -1; //testa se é TRUE ou FALSE
    }
    return 1;
}

int Stack_isFull(Stack *s){
    if (s != NULL)
    {
        return (s->top + 1) == s->size;
    }
    return 0;
}

void Stack_push(Stack *s, int element){
    if (s != NULL)
    {
        if (Stack_isFull(s))
        {
            s->top++;
            s->elements[s->top] = element;
        }
    }
}

int Stack_pop(Stack *s){
    int temp = 0;
    if (s != NULL)
    {
        if (!Stack_isEmpty(s))
        {
            temp = s->elements[s->top];
            s->elements[s->top] = 0;
            s->top--;
            return temp;
        }
    }
    return 0;
}

int Stack_top(Stack *s){
    if (s != NULL)
    {
        if (!Stack_isEmpty(s))
        {
            return s->elements[s->top];
        }
    }
    return 0;
}

int Stack_length(Stack *s){}

void Stack_print(Stack *s){}