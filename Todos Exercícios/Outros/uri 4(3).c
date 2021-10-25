#include <stdio.h>

int main (void)
{
    int teste, N;
    int resto, somaD = 0;
    int i;

    scanf("%d", &teste);

    while (teste--)
    {
        resto = 0;
        somaD = 0;

        scanf("%d", &N);

        for (i = 1; i <= N; i++)
        {
            resto = N % i;

            if (resto == 0 && N != i)
            {
                somaD = somaD + i;
            }
        }

        if (somaD == N)
        {
            printf("%d eh perfeito\n", N);
        }else
            printf("%d nao eh perfeito\n", N);
    }

    return 0;
}
