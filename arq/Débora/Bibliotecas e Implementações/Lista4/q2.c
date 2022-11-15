#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

void print(void *v){
  int *c = (int*) v;
  printf("%d", *c);
}

int main(){
  char letra[] = "6-3*4+1+5";
  Tree *t8 = Tree_create(&letra[6], NULL, NULL);
  Tree *t7 = Tree_create(&letra[4], NULL, NULL);
  Tree *t6 = Tree_create(&letra[2], NULL, NULL);
  Tree *t5 = Tree_create(&letra[0], NULL, NULL);
  Tree *t4 = Tree_create(&letra[5], t7, t8);
  Tree *t3 = Tree_create(&letra[1], t5, t6);
  Tree *t2 = Tree_create(&letra[8], NULL, NULL);
  Tree *t1 = Tree_create(&letra[3], t3, t4);
  Tree *t0 = Tree_create(&letra[7], t1, t2);
  printf("%d\n", Tree_alt(t0));
  Tree_destroy(t0);
  return 0;
}
