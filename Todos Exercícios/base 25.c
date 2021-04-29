#include <stdio.h>

int main (void)
{
    int num1,num2;
    int contador;
    int soma;

    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite outro numero: ");
    scanf("%d", &num2);

    soma = 0;

    if (num1 > num2)
    {
        contador = num2;

        while(contador <= num1)
        {
            soma = soma + contador;
            contador = contador + 1;
        }
    }

    if (num2 > num1)
    {
        contador = num1;

        while(contador <= num2)
        {
            soma = soma + contador;
            contador = contador + 1;
        }
    }

    printf("A soma dos numeros inteiros entre %d e %d eh: %d", num1, num2, soma);

    return 0;
}
