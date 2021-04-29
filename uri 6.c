#include <stdio.h>

int main (void)
{
    int contador;

    contador = 2;

    while(contador <= 100)
    {
        printf("%d\n", contador);
        contador = contador + 2;
    }

    return 0;
}
