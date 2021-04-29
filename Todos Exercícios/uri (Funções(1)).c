#include <stdio.h>

int FuncaoRafael (int x, int y)
{
    int resultado;

    resultado = ((3 * 3) * (x * x)) + (y * y);

    return  resultado;
}

int FuncaoBeto (int x, int y)
{
    int resultado;

    resultado = (2 * (x * x)) + ((5 * 5) * (y * y));

    return  resultado;
}

int FuncaoCarlos (int x, int y)
{
    int resultado;

    resultado = (-100 * x) + (y * y * y);

    return  resultado;
}

int main (void)
{
    int N, X, Y, a, b, c;

    scanf("%d", &N);

    while(N--)
    {
        scanf("%d %d", &X, &Y);

        a = FuncaoRafael(X, Y);
        b = FuncaoBeto(X, Y);
        c = FuncaoCarlos(X, Y);

        if (a > b && a > c)
            printf("Rafael ganhou\n");
        if (b > a && b > c)
            printf("Beto ganhou\n");
        if (c > b && c > a)
            printf("Carlos ganhou\n");
    }


    return 0;
}
