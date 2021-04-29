#include <stdio.h>

int main (void)
{
    int lerValor, menor = 0, posicao;
    int N, i;

    scanf("%d", &N);

    int X[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", &lerValor);

        X[i] = lerValor;

        if(lerValor < menor)
        {
            menor = lerValor;
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
