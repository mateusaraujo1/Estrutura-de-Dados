#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/StackInt.h"

int main(){
  int number, index;
  printf("Total de elementos: ");
  scanf("%d", &index);
  StackInt *stack = StackInt_create(index);
  printf("Numero decimal: ");
  scanf("%d", &number);
  do{
    StackInt_push(stack, number % 2);
    number /= 2;
  }while(number != 0);
  printf("Numero binario: ");
  while(!StackInt_isEmpty(stack)){
    printf("%d", StackInt_pop(stack));
  }
  printf("\n");
  StackInt_destroy(stack);
  return 0;
}
