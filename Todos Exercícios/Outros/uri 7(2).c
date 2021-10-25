#include <stdio.h>

int main (void)
{
    float valor;
    float novo_salario;
    float reajuste;

    scanf("%f", &valor);

    if (valor >= 0 && valor <= 400)
    {
        printf("Novo salario: %.2f\n", novo_salario = valor + ((valor * 15) / 100));
        printf("Reajuste ganho: %.2f\n", reajuste = ((valor * 15) / 100));
        printf("Em percentual: 15 %%\n");
    }

    if (valor > 400 && valor <= 800)
    {
        printf("Novo salario: %.2f\n", novo_salario = valor + ((valor * 12) / 100));
        printf("Reajuste ganho: %.2f\n", reajuste = ((valor * 12) / 100));
        printf("Em percentual: 12 %%\n");
    }

    if (valor > 800 && valor <= 1200)
    {
        printf("Novo salario: %.2f\n", novo_salario = valor + ((valor * 10) / 100));
        printf("Reajuste ganho: %.2f\n", reajuste = ((valor * 10) / 100));
        printf("Em percentual: 10 %%\n");
    }

    if (valor > 1200 && valor <= 2000)
    {
        printf("Novo salario: %.2f\n", novo_salario = valor + ((valor * 7) / 100));
        printf("Reajuste ganho: %.2f\n", reajuste = ((valor * 7) / 100));
        printf("Em percentual: 7 %%\n");
    }

    if (valor > 2000)
    {
        printf("Novo salario: %.2f\n", novo_salario = valor + ((valor * 4) / 100));
        printf("Reajuste ganho: %.2f\n", reajuste = ((valor * 4) / 100));
        printf("Em percentual: 4 %%\n");
    }

    return 0;
}
