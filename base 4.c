#include <stdio.h>

int main (void)

{
    float polegadas, resultado;

    printf("Digite o valor em polegadas: ");
    scanf("%f", &polegadas);

    resultado = polegadas * 2.54;

    printf("O valor %f em polegadas equivale a %f em centimetros\n", polegadas, resultado);

    return 0;
}
