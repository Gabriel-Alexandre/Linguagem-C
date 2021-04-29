#include <stdio.h>
#include<stdbool.h>

bool VerificaOrdem(const int *ar, int tamanho)
{
    int i;
    int aux;
    int somador;

    for(i = 0; i <= tamanho; i++)
    {
        if(i == 0)
            aux = ar[i];

        if(ar[i] > aux)
            somador = somador + 1;
        if(ar[i] < aux)
            return false;
    }

    if(somador == tamanho)
        return true;
}

int main(void)
{
    int ar[5]= {1, 2, 3, 4 ,5};
    int ar2[5] = {5, 4, 3, 2, 1};

    if(VerificaOrdem(ar2, 5))
        printf("true");
    else
        printf("False");

    return 0;
}
