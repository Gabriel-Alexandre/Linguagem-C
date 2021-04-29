#include <stdio.h>

int main (void)
{
    static quantglobal = 0;
    unsigned int N, M, diferenca, quant, resto;

    while(1)
    {
        quantglobal = 0;

        scanf("%d %d", &N, &M);

        if (N == 0 && M == 0)
            break;

        diferenca = M - N;

        if (diferenca > 187){
            printf("impossible");}
        else {

            quant = diferenca / 100;
            resto = diferenca % 100;
            diferenca = resto;

            if (quant > 0)
                quantglobal = quantglobal + quant;

            quant = diferenca / 50;
            resto = diferenca % 50;
            diferenca = resto;

            if (quant > 0)
                quantglobal = quantglobal + quant;

            quant = diferenca / 20;
            resto = diferenca % 20;
            diferenca = resto;

            if (quant > 0)
                quantglobal = quantglobal + quant;

            quant = diferenca / 10;
            resto = diferenca % 10;
            diferenca = resto;

            if (quant > 0)
                quantglobal = quantglobal + quant;

            quant = diferenca / 5;
            resto = diferenca % 5;
            diferenca = resto;

            if (quant > 0)
                quantglobal = quantglobal + quant;

            quant = diferenca / 2;
            resto = diferenca % 2;
            diferenca = resto;

            if (quant > 0)
                quantglobal = quantglobal + quant;


            if (diferenca > 0 || (quantglobal < 2))
                printf("impossible\n");
            if (diferenca == 0 && quantglobal >= 2)
                printf("possible\n");
        }
    }

    return 0;
}
