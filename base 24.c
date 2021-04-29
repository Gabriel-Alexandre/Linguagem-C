#include <stdio.h>

int main (void)
{
    int contador;

    contador = 0;

    while (contador < 100)
    {
        contador = contador + 2;
        printf("%d\n", contador);
    }

    return 0;
}
