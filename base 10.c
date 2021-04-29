#include <stdio.h>

int main (void)

{
    float raio,area,perimetro;

    printf("Digite o valor do raio: ");
    scanf("%f", &raio);

    area = (raio*raio) * 3.14;
    perimetro = raio * (2* 3.14);

    printf("O valor do raio eh: %.1f\n", raio);
    printf("O valor da area eh: %.1f\n", area);
    printf("O valor do perimetro: %.1f\n", perimetro);

    return 0;
}
