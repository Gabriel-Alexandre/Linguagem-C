#include <stdio.h>
#include <string.h>

int main (void)
{
    char Senha[33];
    int aux, aux1, aux2;

    while(scanf("%s", Senha)!= EOF)
    {
        //VerificarLetraMin(Senha)
        while(1)
        {
            char letras[] = "abcdefghijklmnopqrstuvxz";
            int i , j;

            for(i = 0, j = 0; i != '\0', j != '\0'; i++, j++)
            {
                if(letras[i] == Senha[j])
                {
                    aux = 1;
                    break;
                }
            }

            aux = 0;
            break;
        }

        //VerificarLetraMai(Senha)
        while(1)
        {
            char LETRAS[] = "ABCDEFGHIJKLMNOPQRSTUVXZ";
            int i , j;

            for(i = 0, j = 0; i != '\0', j != '\0'; i++, j++)
            {
                if(LETRAS[i] == Senha[j])
                {
                    aux = 1;
                    break;
                }
            }

            aux1 = 0;
            break;
        }

        //VerificarNumero(Senha)
        while(1)
        {
            char Numero[] = "0123456789";
            int i , j;

            for(i = 0, j = 0; i != '\0', j != '\0'; i++, j++)
            {
                if(Numero[i] == Senha[j])
                    aux2 = 1;
            }

            aux2 = 0;
        }

        //VerificarNumero(Senha)

        if((aux == 1) && (aux1 == 1) && (aux2 == 1))
            printf("Senha valida.");
        else
            printf("Senha invalida.");
    }

    return 0;
}


