#include <stdio.h>
#include <string.h>

int main (void)
{
    char Senha[100];

    while(fgets(Senha, 100, stdin))
    {
        int aux = 0, aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 1;
        int i;
        int g;

        for(g = 0; Senha[g] >= ' '; g++);
            Senha[g] = '\0';

        int tamanho;

        tamanho = strlen(Senha);

        if(tamanho >= 6 && tamanho <= 32)
            aux = 1;

        for(i = 0; i < tamanho; i++)
        {
            if(Senha[i] >= 65 && Senha [i] <= 90)
                aux1 = 1;
            else if(Senha[i] >= 97 && Senha[i] <= 122)
                aux2 = 1;
            else if(Senha[i] >= 48 && Senha[i] <= 57)
                aux3 = 1;
            else if((Senha[i] >= 20 && Senha[i] <= 47) || (Senha[i] >= 58 && Senha[i] <= 64) || (Senha[i] >= 91 && Senha[i] <= 96) ||
               (Senha[i] >= 123 && Senha[i] <= 127))
                aux4 = 0;
        }

        if((aux == 1) && (aux1 == 1) && (aux2 == 1) && (aux3 == 1) && (aux4 == 1))
        {
            printf("Senha valida.\n");
        }else{
            printf("Senha invalida.\n");}
    }

    return 0;
}
