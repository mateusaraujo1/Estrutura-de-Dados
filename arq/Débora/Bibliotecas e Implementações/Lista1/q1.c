/*Crie uma função que receba uma string e retorne o ponteiro para uma nova string invertida.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inversao(char c[]){
  char *cPtr = NULL;
  cPtr = malloc(strlen(c) + 1);
  int i, j = strlen(c) - 1;
  for(i = 0; i < strlen(c); i++, j--)
    cPtr[i] = c[j];
  cPtr[i] = '\0';
  return cPtr;
}

int main(){
  char palavra[] = "string";
  printf("%s\n", inversao(palavra));
  return 0;
}
