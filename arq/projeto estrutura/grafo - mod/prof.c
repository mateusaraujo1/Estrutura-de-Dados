#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct
{
int topo;
int el[30];
}Pilha;
typedef struct
{
int fim;
int el[30];
}Visitados;
typedef struct
{
int el[30];
}Status ;
typedef struct
{
int adj[30][30];
int indice_inc;
int max;
}Vetor;
void cria_aresta(Vetor *mVetor, int vp, int vu){
// verifica se não se trata de um laço
if (vp==vu){
puts(“\n### ERRO :Primeiro e segundo vertices iguais, nao e permitido lacos ###\n”);
// verifica se a aresta já existe
}else if((mVetor->adj[vp][vu] == 1)||(mVetor->adj[vu][vp] == 1)){
printf(“\n### ERRO : A arresta V%d<—–>V%d ja existe ###\n”,vp,vu);
}else{ // cria aresta na matriz
mVetor->adj[vp][vu] = 1;
mVetor->adj[vu][vp] = 1;
mVetor->indice_inc++;
printf(“\n### CONCLUIDO :Arresta V%d<—–>V%d criada com sucesso ###\n”,vp,vu);
}
}
void apaga_aresta(Vetor *mVetor, int vp, int vu){
// verifica se aresta existe
if (( mVetor->adj[vp][vu]==1) || ( mVetor->adj[vu][vp]==1)) {
//apaga a aresta da matriz de adjacencia
mVetor->adj[vp][vu]=0;
mVetor->adj[vu][vp]=0;
// decrementa o indice
mVetor->indice_inc–;
printf(“\n### CONCLUIDO :Arresta V%d<—–>V%d EXCLUIDA com sucesso ###\n”,vp,vu);
}else{
printf(“\n### ERRO : Impossivel excluir, a aresta %d<—–>V%d nao existe ###\n”,vp,vu);
}
}
void cria_vetores(Vetor *mVetor, Visitados *mvis, Status *mstatus, Pilha *mpilha, int maximo){
//inicializacao da matris de adjacencia grafo
for (int i=0; i for (int j=0; jadj[i][j] = 0;
mVetor->indice_inc=0;
mVetor->max=maximo;
for (int i=0; iel[i]=0;
}
mvis->fim=0;
for (int i=0; iel[i]=0;
}
for (int i=0; iel[i]=0;
}
mpilha->topo=0;
}
void zerabusca(Vetor *mVetor, Visitados *mvis, Status *mstatus, Pilha *mpilha){
int maximo = mVetor->max;
for (int i=0; iel[i]=0;
}
mvis->fim=0;
for (int i=0; iel[i]=0;
}
for (int i=0; iel[i]=0;
}
mpilha->topo=0;
}
void imprime_adj(Vetor *mVetor){
printf(“\n=========================== Matriz de Adjacencia ==============================\n”);
printf(“===============================================================================\n”);
for(int i=0; imax;i++)
if(i==0){
printf(“|\tV0”);
}else if(i!=(mVetor->max-1)){
printf(“\tV%d”,i);
}else{
printf(“\tV%d\t|”,i);
}
for(int i=0; imax;i++){
printf(“\n|V%d\t”,i);
for (int j=0;jmax;j++){
printf(“%d\t”,mVetor->adj[i][j]);
}
printf(“|”);
}
printf(“\n===============================================================================\n\n”);
}
void busca_profundidade(Vetor *mvetor, Visitados *mVis, Status *mstatus, Pilha *mpilha, int inicio){
int novoinicio =99;
// adiciona o vertice inicio a lista de visitados
if(mstatus->el[inicio]!=1){
mVis->el[mVis->fim]= inicio;
mVis->fim++;
mstatus->el[inicio]=1;
// 1 visitado, 2 na pilha, 0 nada feito ainda
}
//i linha, j coluna
for (int i=0; imax; i++)
if(mvetor->adj[i][inicio]==1){
if(novoinicio==99){
if(mstatus->el[i]==0){
novoinicio=i;
}
}else if(mstatus->el[i]!=1){
mpilha->el[mpilha->topo]=i;
mpilha->topo++;
mstatus->el[i]=2;
}
}
if(novoinicio!=99){// se foi encontado um novo vertice não visitado
busca_profundidade(mvetor, mVis, mstatus, mpilha, novoinicio);
}else if(mpilha->topo!=0){// se não foi encontado um novo vertice
mpilha->topo–;
busca_profundidade(mvetor, mVis, mstatus, mpilha, mpilha->el[mpilha->topo]);
//é desempilhado
}else{
printf(“\n==================== Resultado da Busca em Profundidade =======================\n”);
printf(“===============================================================================\n”);
for (int i=0;ifim;i++){
printf(“%d\t”,mVis->el[i]);
}
printf(“\n===============================================================================\n”);
}
}
int main(){
int op,vp,vu,valor,novo;
Vetor mVetor;
Pilha mPilha;
Visitados mVisitados;
Status mStatus;
puts(“\nQuantos Vertices tera o grafo? (Para impressao da matriz na tela: maximo 9)”);
scanf(“%d”,&novo);
cria_vetores(&mVetor,&mVisitados, &mStatus, &mPilha, novo);
puts(“### CONCLUIDO :Novo Grafo iniciado com sucesso ###”);
system (“pause”);
do
{
system(“cls”);
printf(“===============================================================================\n”);
printf(“\n GRAFO.v1.3 – Matriz de Adjacencia/Busca em Profundidade\n”);
printf(“\n===============================================================================\n”);
puts (” 1|- Iniciar Novo Grafo”);
puts (” 2|- Criar Aresta”);
puts (” 3|- Apagar Aresta”);
puts (” 4|- Imprimir Matriz De Adjacencia”);
puts (” 5|- Realizar Busca em Profundidade”);
puts (” 6|- Sair”);
printf(“\n===============================================================================\n”);
scanf(“%d”, &op);
switch(op)
{
case 1: {
puts(“\nTem certeza que deseja inicar um novo Grafo? \n ( 1 = SIM , 0 = NAO )”);
scanf(“%d”,&novo);
if (novo==1){
puts(“\nQuantos Vertices tera o grafo? (Para impressao da matriz na tela: maximo 9)”);
scanf(“%d”,&novo);
cria_vetores(&mVetor,&mVisitados, &mStatus, &mPilha, novo);
puts(“### CONCLUIDO :Novo Grafo iniciado com sucesso ###”);
}else{
puts(“### OPERACAO CANCELADA: Novo Grafo nao iniciado ###”);
}
system (“pause”);
break; }
case 2:{puts(“Digite o PRIMEIRO vertice para a nova aresta:”);
scanf(“%d”,&vp);
puts(“Digite o SEGUNDO vertice para a nova aresta:”);
scanf(“%d”,&vu);
cria_aresta(&mVetor,vp,vu);
system (“pause”);
break; }
case 3:{puts(“Digite o PRIMEIRO vertice da aresta que deseja excluir:”);
scanf(“%d”,&vp);
puts(“Digite o SEGUNDO vertice da aresta que deseja excluir:”);
scanf(“%d”,&vu);
apaga_aresta(&mVetor,vp,vu);
system (“pause”);
break; }
case 4:{ imprime_adj(&mVetor);
system (“pause”);
break; }
case 5:{ zerabusca(&mVetor,&mVisitados, &mStatus, &mPilha);
puts(“Digite o vertice inicial da Busca”);
scanf(“%d”,&vp);
busca_profundidade(&mVetor, &mVisitados, &mStatus, &mPilha, vp);
system (“pause”);
break; }
}
} while (op!=6);
return 1;
}