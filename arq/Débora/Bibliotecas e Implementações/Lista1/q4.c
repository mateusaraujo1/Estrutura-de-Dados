/*
Escreva uma função chamada 𝗺𝗮𝗽 que receba como parâmetro um vetor de números reais 𝗔 contendo 𝗡 elementos,
um número real 𝗞 e um ponteiro para função (𝚏𝚕𝚘𝚊𝚝(*𝚘𝚙𝚎𝚛𝚊𝚝𝚒𝚘𝚗) (𝚏𝚕𝚘𝚊𝚝 𝚊, 𝚏𝚕𝚘𝚊𝚝 𝚋) ).
A função deve retornar o ponteiro para um novo vetor 𝗕 de 𝗡 elementos alocado dinamicamente, em que 𝙱[𝚒] = 𝚘𝚙𝚎𝚛𝚊𝚝𝚒𝚘𝚗( 𝙰[ 𝚒 ], 𝚔 ).
*/

#include <stdlib.h>
#include <stdio.h>

float operacao(float a, float b){
  return a + b;
}

float *map(float a[], int n, float k, float (*operacao)(float, float)){
  float *cPtr;
  int i;
  cPtr = malloc(sizeof(float) * n);
  for(i = 0; i < n; i++)
    cPtr[i] = (*operacao)(a[i], k);
  return cPtr;
}

void imprimi(float ptr[], int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%.2f\n", ptr[i]);
}

int main(){
  float num, v[5] = {0};
  printf("Digite um numero:\n");
  scanf("%f", &num);
  imprimi(map(v, 5, num, operacao), 5);
  return 0;
}
