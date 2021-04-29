#include <stdio.h>

int main (void)
{
    int base, expoente;
    int contador, numero;

    printf("Digite o numero da base: ");
    scanf("%d", &base);
    printf("Digite o numero do expoente: ");
    scanf("%d", &expoente);

    numero = base;
    contador = 1;

    while (contador < expoente)
    {
        numero = numero * base;
        contador = contador + 1;
    }

    printf("O resultado eh: %d",numero);

    return 0;
}
