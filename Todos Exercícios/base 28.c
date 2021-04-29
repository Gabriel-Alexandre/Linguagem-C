#include <stdio.h>

int main (void)
{
    float saldoI, saldoF;
    float saldoV;

    printf("Digite o seu saldo: ");
    scanf("%f", &saldoI);
    printf("Digite seu ganho ou despesa: ");
    scanf("%f", &saldoV);

    saldoF = saldoI + saldoV;

    while (saldoV != 0)
    {
        printf("Digite seu ganho ou despesa: ");
        scanf("%f", &saldoV);
        saldoF = saldoF + saldoV;
    }

    printf("saldo final: %.1f", saldoF);

    return 0;
}
