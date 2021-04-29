#include <stdio.h>

int main (void)
{
    int numero;
    int contador = 1;

    printf("Digite o numero: ");
    scanf("%d", &numero);

    if (numero > 17)
        printf("numero muito alto\n");
    else if (numero < 17)
        printf("numero muito baixo\n");
    else if (numero = 17)
        printf("voce venceu!\n");

    while((numero != 17) && (contador != 5))
    {
        printf("Digite o numero: ");
        scanf("%d", &numero);
        contador = contador + 1;

        if (numero > 17)
            printf("numero muito alto\n");
        else if (numero < 17)
            printf("numero muito baixo\n");
        else if (numero == 17)
            printf("voce venceu!\n");
    }

    if (contador == 5)
        printf("voce perdeu!\n");

    printf("Foram digitados %d palpites", contador);

    return 0;
}
