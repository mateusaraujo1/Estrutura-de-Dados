#include <stdlib.h>
#include <stdio.h>
#include "biblioteca/StackInt.h"

struct StackInt {
  int size;
  int top;
  int *elements;
};

StackInt *StackInt_create(int size){ //funcao que cria uma pilha
  int i;
  StackInt *ptr = malloc(sizeof(StackInt));
  ptr->size = size;
  ptr->top = -1;
  ptr->elements = malloc(sizeof(int) * size);
  for(i = 0; i < size; i++)
    ptr->elements[i] = 0;
  return ptr;
}

void StackInt_destroy(StackInt *stack){ //funcao que encerra/destroi uma pilha
  free(stack);
  free(stack->elements);
  stack = NULL;
}

int StackInt_isEmpty(StackInt *stack){ //funcao que verifica se a pilha esta vazia
  if(stack->top == -1) return 1;
  else return 0;
}

int StackInt_isFull(StackInt *stack){ //funcao que verifica se a pilha esta cheia
  if(stack->top == stack->size - 1) return 1;
  else return 0;
}

void StackInt_push(StackInt *stack, int element){ //insercao de um elemento no topo da pilha
  if(StackInt_isFull(stack) == 1) abort();
  else{
    stack->top++;
    stack->elements[stack->top] = element;
  }
}

int StackInt_pop(StackInt *stack){ //acesso e remoção do elemento no topo da pilha
  int i;
  if(StackInt_isEmpty(stack) == 1) abort();
  else{
    i = stack->elements[stack->top];
    stack->elements[stack->top] = 0;
    stack->top--;
    return i;
  }
}

int StackInt_top(StackInt *stack){ //acesso ao elemento no topo da pilha sem sua remoção
  if(StackInt_isEmpty(stack) == 1) abort();
  else{
    return stack->elements[stack->top];
  }
}
