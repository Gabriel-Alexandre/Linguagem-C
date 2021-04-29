#include <stdio.h>

int main (void)
{
    int numero;

    scanf("%d", &numero);

    switch(numero)
    {
        case 1:
            puts("Domingo");
            break;
        case 2:
            puts("Segunda-feira");
            break;
        case 3:
            puts("Terça-feira");
            break;
        case 4:
            puts("Quarta-feira");
            break;
        case 5:
            puts("Quinta-feira");
            break;
        case 6:
            puts("Sexta-feira");
            break;
        case 7:
            puts("Sabado");
            break;
        default:
            puts("Nao existe dia da semana correspondente.");
    }

    return 0;
}
