#include <stdio.h>

int main (void)

{
    float raio, area;

    printf("Digite o valor do raio: ");
    scanf("%f", &raio);

    area = 3.14 * (raio * raio);

    printf("O valor da area do circulo eh: %f\n", area);

    return 0;
}
