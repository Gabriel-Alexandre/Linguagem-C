#include <stdio.h>

int main (void)
{
    int contador = 0;
    float idade;
    float total = 0;
    float media;

    idade = 1;

    while(idade > 0)
    {
        scanf("%f", &idade);

        if (idade > 0)
        {
            total = total + idade;
            contador = contador + 1;
        }
    }

    media = total / contador;

    printf("%.2f\n", media);

    return 0;
}
