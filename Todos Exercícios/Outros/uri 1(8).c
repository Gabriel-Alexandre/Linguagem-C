#include <stdio.h>

int main (void)
{
    int teste, i;
    int contador;

    scanf("%d", &teste);

    while(teste--)
    {
        contador = 0;

        char str[100];

        scanf("%s", str);

        for(i = 0; str[i] != '\0'; i++)
        {
            if(str[i] == '0')
            {
                contador = contador + 6;
            }

            if(str[i] == '1')
            {
                contador = contador + 2;
            }

            if(str[i] == '2')
            {
                contador = contador + 5;
            }

            if(str[i] == '3')
            {
                contador = contador + 5;
            }

            if(str[i] == '4')
            {
                contador = contador + 4;
            }

            if(str[i] == '5')
            {
                contador = contador + 5;
            }

            if(str[i] == '6')
            {
                contador = contador + 6;
            }

            if(str[i] == '7')
            {
                contador = contador + 3;
            }

            if(str[i] == '8')
            {
                contador = contador + 7;
            }

            if(str[i] == '9')
            {
                contador = contador + 6;
            }
        }

        printf("%d leds\n", contador);

    }

    return 0;
}
