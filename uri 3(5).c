#include <stdio.h>

int main (void)
{
    int X, Y, maior, menor, aux, soma = 0;
    int i, j;

    scanf("%d", &X);
    scanf("%d", &Y);

    maior = X > Y ? X : Y;
    menor = X > Y ? Y : X;

    for (i = menor, j = 13; i <= maior, j <= maior; i++, j = j + 13)
    {
        aux = 0;
        aux = i % j;

        if (aux != 0)
            soma = soma + i;
    }

    printf("%d", soma);

    return 0;
}
