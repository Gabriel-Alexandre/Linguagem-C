#include <stdio.h>

int main(void)
{
    int numero;
    int i, j;
    int resto, somaD;

    scanf("%d", &numero);

    for (i = 1; i <= numero; i++)
    {
        somaD = 0;
        resto = 0;

        for (j = 1; j <= i; j++)
        {
            resto = i % j;

            if (resto == 0)
                somaD += 1;
        }

        if (somaD == 2)
            printf("%d\n", i);
    }

    return 0;
}
