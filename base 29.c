#include <stdio.h>

int main (void)
{
    int fatorial;
    int contador;
    int numero;

    printf("Digite o numero fatorial: ");
    scanf("%d", &fatorial);

    contador = 1;
    numero = fatorial;

    while(contador < numero)
    {
        fatorial = fatorial * contador;
        contador = contador + 1;
    }

    printf("O resultado eh: %d", fatorial);

    return 0;
}
