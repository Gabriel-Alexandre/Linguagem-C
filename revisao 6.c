#include <stdio.h>

int main (void)
{
    int quantprodutos, somaprodutos = 0;
    int valor;

    while (1)
    {
        scanf("%d %d", &valor, &quantprodutos);

        if (valor < 0 || quantprodutos < 0)
            break;

        somaprodutos = somaprodutos + (quantprodutos * valor);
    }

    printf ("O valor total da venda eh: %d", somaprodutos);

    return 0;
}
