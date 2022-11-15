#include <stdlib.h>
#include <stdio.h>
#include "../biblioteca/Queue.h"

struct Queue{
  int length; //capacidade maxima da fila
  int total; //que indica o total de itens guardados na fila
  int begin; //inicio da fila
  int end; //fim da fila
  void **elements; //itens da fila
};

int Queue_next(Queue *queue, int index){
  if(index >= 0) return (index + 1) % queue->length;
  else return 0;
}

Queue *Queue_create(int length){
  Queue  *queue = malloc(sizeof(Queue));
  queue->length = length;
  queue->total = 0;
  queue->begin = 0;
  queue->end = -1;
  queue->elements = calloc(length, sizeof(void *));
  return queue;
}

void Queue_destroy(Queue *queue){
  free(queue->elements);
  free(queue);
}

int Queue_isEmpty(Queue *queue){
  return (queue->total == 0);
}

int Queue_isFull(Queue *queue){
  return (queue->total == queue->length);
}
void Queue_push(Queue *queue, void *element){
  if(!Queue_isFull(queue)){
    queue->end = Queue_next(queue, queue->end);
    queue->elements[queue->end] = element;
    queue->total++;
  }
}

void *Queue_pop(Queue *queue){
  if(!Queue_isEmpty(queue)){
    void *beginElement = NULL;
    beginElement = queue->elements[queue->begin];
    queue->elements[queue->begin] = NULL;
    queue->begin = Queue_next(queue, queue->begin);
    queue->total--;
    return beginElement;
  }
}

void *Queue_begin(Queue *queue){
  if(!Queue_isEmpty) return queue->elements[queue->begin];
}

void *Queue_end(Queue *queue){
  if(!Queue_isEmpty) return queue->elements[queue->end];
}

int Queue_getLength(Queue *queue){
  return queue->length;
}

void Queue_print(Queue *queue, void (*print)(void *)){
  int i = queue->begin;
  while(i != queue->end){
    print(queue->elements[i]);
    i = Queue_next(queue, i);
  }
}
