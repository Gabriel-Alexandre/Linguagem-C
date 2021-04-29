/*
=============================================================================
Name: base 8.c
Author: Gabriel A.
Description: how many paint cans does it take to paint a wall on c
how it works(in portuguese):

1- os dados da altura, do comprimento, do volume e rendimento são pedidos
ao usuario.
2- a area eh calculada.
3- o rendimento eh calculado.
4- a quantidades de latas eh calculada.(utilizando uma regra de tres composta
                                        com os valores da area e do rendimento
                                        ja calculados).
5- o programa informa a quantidade de latas necessarias para pintar a parede.
==============================================================================
*/
#include <stdio.h>

int main (void)
{

    float altura, comprimento, rendimento, volume, area, quantidadeLatas;

    puts("Bem-vindo");
    printf("Digite o valor da altura -em metros- da parede: ");
    scanf("%f", &altura);
    printf("Digite o valor do comprimento -em metros- da parede: ");
    scanf("%f", &comprimento);
    printf("Digite o valor do volume -em litros- da lata de tinta : ");
    scanf("%f", &volume);
    printf("Digite o valor do rendimento -em m2/litro- da tinta: ");
    scanf("%f", &rendimento);

    area = altura * comprimento;
    rendimento = area / volume;
    quantidadeLatas = (1/rendimento) * area;

    printf("A quantidade de latas necessarias para pintar a parede eh: %f\n", quantidadeLatas);

    return 0;
}
