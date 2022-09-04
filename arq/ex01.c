#include <stdio.h>
#define tam 5

void mostra(int vetor[], int posicao) {
    if (posicao < tam)
    {
        printf("%d ", vetor[posicao]);
        return mostra(vetor, posicao+1);
    }
}

float somaReais(float vetor[], int soma, int posicao) {
    if (posicao < tam)
    {
        soma += vetor[posicao];
        return somaReais(vetor, soma, posicao+1);
    }
    else
        return soma;
}

int main()
{
    float vetor[] = {1, 3, 5, 7, 9}, posicao = 0, soma = 0;
    //mostra(vetor, posicao); //mudar vetor float para int

    printf("\n%.2f", somaReais(vetor, soma, posicao));
    return 0;
}
