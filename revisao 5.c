#include <stdio.h.>

int main (void)
{
    int n, a1, an, c = 0;
    int aux = 0, razao, razao2 = 0, somaT;
    int gab = 1;

    do
    {
        razao = 0;

        scanf("%d", &n);

        if (n == -1)
        {
            if (gab != 0)
                razao = razao2;

            break;
        }

        razao = n - aux;
        aux = n;
        c++;

        if (razao == razao2)
            continue;

        if (c == 1)
        {
            razao2 = razao;
            a1 = n;
            continue;
        }

        if (razao2 != (n - aux))
        {
            gab = 0;
            continue;
        }

    }while (1);

    if (razao == razao2)
    {
        an = a1 + (c - 1) * razao2;
        somaT = ((a1 + an) * c) / 2;

        printf("Razao: %d\n", razao2);
        printf("Soma dos termos: %d\n", somaT);
    }else
        printf("Essa sequencia nao constitui uma p.a.");

    return 0;
}
