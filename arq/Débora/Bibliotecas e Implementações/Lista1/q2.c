/*Crie uma estrutura 𝗖𝗮𝗿 com os membros: 𝗯𝗿𝗮𝗻𝗱, 𝗺𝗼𝗱𝗲𝗹, 𝘃𝗮𝗹𝘂𝗲, 𝗸𝗺_𝗹 e 𝗸𝗺_𝗵.
Crie uma função que retorne o ponteiro para um vetor de 𝗡 elementos tipo 𝘀𝘁𝗿𝘂𝗰𝘁𝗖𝗮𝗿 alocado dinamicamente.
Caso 𝗡 seja negativo ou igual a zero, um ponteiro nulo deverá ser retornado.
Use a função para criar um vetor de tamanho 5, preencha suas informações e imprima o vetor.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char brand[10];
  char model[10];
  float value;
  float km_l;
  float km_h;
}Car;

Car *retornoPtr(int n){
  Car *rPtr;
  if(n >= 1) rPtr = malloc(sizeof(Car) * n);
  else rPtr = NULL;
  return rPtr;
}

void incrementaImprimi(Car ptr[], int n){
  int i;
  for(i = 0; i < n; i++){
    printf("Marca do carro:\n");
    scanf("%s", ptr[i].brand);
    printf("Modelo do carro:\n");
    scanf("%s", ptr[i].model);
    printf("Valor:\n");
    scanf("%f", &ptr[i].value);
    printf("km_l\n");
    scanf("%f", &ptr[i].km_l);
    printf("km_h\n");
    scanf("%f", &ptr[i].km_h);
  }
  for(i = 0; i < n; i++){
    printf("%s\n", ptr[i].brand);
    printf("%s\n", ptr[i].model);
    printf("%.2f\n", ptr[i].value);
    printf("%.2f\n", ptr[i].km_l);
    printf("%.2f\n", ptr[i].km_h);
    printf("\n");
  }
}

int main(){
  int num;
  printf("Total de elementos: \n");
  scanf("%d", &num);
  if(retornoPtr(num) > 0) incrementaImprimi(retornoPtr(num), num);
  else printf("Erro: %s", retornoPtr(num));
  return 0;
}
