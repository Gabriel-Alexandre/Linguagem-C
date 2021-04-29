#include <stdio.h.>
#include <string.h>

int VerificaVogais(const char*ar, int tamanho)
{
    int i;
    int QuantidadeVogais = 0;
    char aux[tamanho];

    strcpy(aux, ar);

    for(i = 0; aux[i] != '\0'; i++)
    {
        if ((aux[i] == 'a') || (aux[i] == 'e') || (aux[i] == 'i') || (aux[i] == 'o') || (aux[i] == 'u'))
            QuantidadeVogais++;
    }

    return QuantidadeVogais;
}

int main(void)
{
    char ar[50]= "abcdefghioiu";
    char ar2[50] = "aeiao";

    printf("%d\n", VerificaVogais(ar, 50));

    return 0;
}
