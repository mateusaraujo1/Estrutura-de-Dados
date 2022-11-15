#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct{
  char nome[30];
  int idade;
}pessoas;

int compar(void *a, void *b){
    char *s1 = (char*)a;
    char *s2 = (char*)b;
    return strcmp(s1, s2);
}

void print(void *a){
  printf("%s", (char*)a);
}

int main(){
  pessoas n[] = {
                  {"Joao", 25},
                  {"Caio", 20},
                  {"Ana", 23},
                  {"Pedro", 20},
                  {"Jane", 30},
                  {"Marcos", 19},
                  {"Bruna", 23},
                  {"Felipe", 20},
                  {"Renata", 35}
                };
  Graph *g = Graph_create(compar);
  
  Graph_insert(g, &n[0].nome); //Joao - ok
  Graph_insert(g, &n[1].nome); //Caio - ok
  Graph_insert(g, &n[2].nome); //Ana - ok
  Graph_insert(g, &n[3].nome); //Pedro - ok
  Graph_insert(g, &n[4].nome); //Jane - ok
  Graph_insert(g, &n[5].nome); //Marcos - ok
  Graph_insert(g, &n[6].nome); //Bruna - ok
  Graph_insert(g, &n[7].nome); //Felipe - ok
  Graph_insert(g, &n[8].nome); //Renata - ok

  Graph_link(g, &n[0].nome, &n[2].nome);
  Graph_link(g, &n[0].nome, &n[3].nome); //Ligacoes do Joao
  Graph_link(g, &n[0].nome, &n[1].nome);

  //Caio nao tem nenhuma ligacao

  Graph_link(g, &n[2].nome, &n[0].nome);
  Graph_link(g, &n[2].nome, &n[4].nome); //Ligacoes da Ana

  Graph_link(g, &n[3].nome, &n[1].nome);
  Graph_link(g, &n[3].nome, &n[4].nome);  //Ligacoes do Pedro
  Graph_link(g, &n[3].nome, &n[5].nome);
  Graph_link(g, &n[3].nome, &n[6].nome);

  Graph_link(g, &n[4].nome, &n[3].nome);
  Graph_link(g, &n[4].nome, &n[5].nome);  //Ligacoes da Jane
  Graph_link(g, &n[4].nome, &n[6].nome);

  Graph_link(g, &n[5].nome, &n[7].nome);
  Graph_link(g, &n[5].nome, &n[8].nome); //Ligacoes do Marcos

  Graph_link(g, &n[6].nome, &n[8].nome); //LIgacoes da Bruna

  Graph_link(g, &n[7].nome, &n[5].nome);
  Graph_link(g, &n[7].nome, &n[8].nome); // Ligacoes do Felipe

  //Renata nao tem nenhuma ligacao

  char nome[30];
  printf("Nome: \n");
  scanf("%s", nome);
  for(int i = 0; i < 9; i++){
    if(strcmp(n[i].nome, nome) == 0){
      printf("Seguindo: %d\n", Vertex_numberLinks(g, &n[i].nome));
    }
  }
  Graph_destroy(g);
  return 0;
}
