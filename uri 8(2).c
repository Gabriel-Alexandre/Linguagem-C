#include <stdio.h>

int main (void)
{
    int N;
    int contador = 0;
    int total = 0;
    float quantia;
    float total_coelhos = 0;
    float total_ratos = 0;
    float total_sapos = 0;
    float percentual_coelhos;
    float percentual_ratos;
    float percentual_sapos;
    char aux, C, R, S;

    scanf("%d", &N);

    while (contador < N)
    {
        scanf("%f %c", &quantia, &aux);

        total = total + quantia;

        if (aux == 'C')
           total_coelhos = total_coelhos + quantia;
        if (aux == 'R')
           total_ratos = total_ratos + quantia;
        if (aux == 'S')
           total_sapos = total_sapos + quantia;

        contador = contador + 1;
    }

        printf("Total: %d cobaias\n", total);
        printf("Total de coelhos: %.0f\n", total_coelhos);
        printf("Total de ratos: %.0f\n", total_ratos);
        printf("Total de sapos: %.0f\n", total_sapos);
        printf("Percentual de coelhos: %.2f %%\n", percentual_coelhos = (total_coelhos * 100) / total);
        printf("Percentual de ratos: %.2f %%\n", percentual_ratos = (total_ratos * 100) / total);
        printf("Percentual de sapos: %.2f %%\n", percentual_sapos = (total_sapos * 100) / total);

    return 0;
}
