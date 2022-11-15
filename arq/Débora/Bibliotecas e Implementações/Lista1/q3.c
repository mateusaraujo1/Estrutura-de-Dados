/*
Escreva uma função que receba por parâmetro os valores inteiros e positivos
𝗠 e 𝗡 e retorne um ponteiro para uma matriz 𝗠 × 𝗡 alocada dinamicamente.
Essa matriz deverá ter todas as posições inicializadas com zero.
*/

#include <stdio.h>
#include <stdlib.h>

int** matriz(unsigned int Linhas, unsigned int Colunas){
  int i,j;
  int **m = malloc(Linhas * sizeof(int));
  for (i = 0; i < Linhas; i++){
    m[i] = malloc(Colunas * sizeof(int));
    for (j = 0; j < Colunas; j++)
      m[i][j] = 0;
  }
  return m;
}

int main(){
  unsigned int linha, coluna;
  int i, j;
  printf("linha:\n");
  scanf("%u", &linha);
  printf("Coluna:\n");
  scanf("%u", &coluna);
  int **ptr = matriz(linha, coluna);
  for(i = 0; i< linha; i++){
    for(j = 0; j< coluna; j++)
      printf("%d ", ptr[i][j]);
    printf("\n");
  }
  return 0;
}
