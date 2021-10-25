#include <stdio.h>

int main (void)
{
    int teste, N;
    int resto, primo;
    int i, contador;

    scanf("%d", &teste);

    while (teste--)
    {
        contador = 0;
        resto = 0;
        primo = 0;

        scanf("%d", &N);

        for (i = 1; i <= N; i++)
        {
            resto = N % i;

            if (resto == 0)
                contador++;
        }

        if (contador == 2)
        {
            printf("%d eh primo\n", N);
        }else
            printf("%d nao eh primo\n", N);
    }

    return 0;
}
