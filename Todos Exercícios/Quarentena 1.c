#include <stdio.h>

int main (void)
{
    char Nome[30];
    double Salario, VendasEF, aux, Total;

    scanf("%s", &Nome);
    scanf("%lf", &Salario);
    scanf("%lf", &VendasEF);

    aux = (VendasEF * 15) / 100;
    Total = Salario + aux;

    printf("TOTAL = R$ %.2lf\n", Total);

    return 0;
}
