/*
  Considere a seguinte declaração: 𝚒𝚗𝚝 𝚊, *𝚋, **𝚌, ***𝚍;.
  Escreva um programa que leia a variável a e calcule e exiba o dobro,
  o triplo e o quádruplo desse valor utilizando apenas os ponteiros 𝗯, 𝗰 e 𝗱.
  O ponteiro 𝗯 deve ser usado para calcular o dobro, 𝗰, o triplo, e 𝗱, o quádruplo.
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
  int a;
  int *b, **c, ***d;
  printf("Digite um numero: \n");
  scanf("%d", &a);
  b = &a;
  *b = *b * 2;
  printf("%d\n", *b);
  c = &b;
  **c = (**c/2) * 3;
  printf("%d\n", **c);
  d = &c;
  ***d = (***d/3) * 4;
  printf("%d\n", ***d);
  return 0;
}
