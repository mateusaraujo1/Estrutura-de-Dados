#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int compar(void *x, void *y){
    int a,b,n;
    a = *((int *)x);
    b = *((int *)y);
    n = a - b;
    return n;
}

void print(void *n){
    int a = *((int *)n);
    if(n){
        printf("%d",a);
    }else{
        printf("NULL");
    }
}

int main(){
    int i,n[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    float f[] = {2,2.8,3,3.6,4,4.5,5,7,7.3};

Graph *g = Graph_create(compar);

for(i = 14 ; i >= 0; i--){
    Graph_insert(g,&n[i]);
}

Graph_link(g,&n[0],&n[1],&f[2]);
Graph_link(g,&n[0],&n[3],&f[0]);

Graph_link(g,&n[1],&n[4],&f[0]);

Graph_link(g,&n[2],&n[0],&f[3]);
Graph_link(g,&n[2],&n[3],&f[2]);

Graph_link(g,&n[3],&n[4],&f[2]);
Graph_link(g,&n[3],&n[7],&f[0]);

Graph_link(g,&n[4],&n[5],&f[7]);
Graph_link(g,&n[4],&n[8],&f[0]);
Graph_link(g,&n[4],&n[9],&f[8]);

Graph_link(g,&n[5],&n[9],&f[0]);

Graph_link(g,&n[6],&n[2],&f[0]);

Graph_link(g,&n[7],&n[6],&f[2]);
Graph_link(g,&n[7],&n[11],&f[4]);

Graph_link(g,&n[8],&n[7],&f[2]);
Graph_link(g,&n[8],&n[12],&f[4]);

Graph_link(g,&n[9],&n[8],&f[7]);
Graph_link(g,&n[9],&n[13],&f[4]);

Graph_link(g,&n[10],&n[6],&f[4]);
Graph_link(g,&n[10],&n[11],&f[2]);

Graph_link(g,&n[11],&n[6],&f[6]);
Graph_link(g,&n[11],&n[10],&f[2]);
Graph_link(g,&n[11],&n[12],&f[2]);

Graph_link(g,&n[12],&n[11],&f[2]);
Graph_link(g,&n[12],&n[13],&f[7]);

Graph_link(g,&n[13],&n[12],&f[7]);
Graph_link(g,&n[13],&n[14],&f[5]);

Graph_link(g,&n[14],&n[12],&f[1]);

Graph_print(g, print);

Graph_destroy(g);
return 0;

}