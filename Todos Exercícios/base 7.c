#include <stdio.h>

int main (void)

{
    float comprimento, largura, area, pontenciaI;

    printf("Digite o comprimento -em metros- : ");
    scanf("%f", &comprimento);
    printf("Digite a largura -em metros- : ");
    scanf("%f",&largura);

    area = comprimento * largura;
    pontenciaI = area * 18;

    printf("Com area = %f metros, pontencia de iluminaçao = %f watts", area, pontenciaI);

    return 0;
}

