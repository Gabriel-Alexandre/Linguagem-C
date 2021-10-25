#include <stdio.h>

int main (void)
{
    int valor;
    int maior, menor;

    printf("Digite o valor: ");
    scanf("%d", &valor);

    maior = valor;
    menor = valor;

    while(valor != 0)
    {
        printf("Digite o valor: ");
        scanf("%d", &valor);

        if(valor > maior && valor != 0)
        {
            maior = valor;
        }

        if(valor < menor && valor != 0)
        {
            menor = valor;
        }
    }

    printf("O maior valor eh: %d\n", maior);
    printf("O menor valor eh: %d\n", menor);

    return 0;
}
