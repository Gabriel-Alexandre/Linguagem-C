#include <stdio.h>
#include <math.h>

void CalculaHexagono(float l, float *area, float *perimetro)
{
    *area = ((3 * (l * l)) * sqrt(3)) / 2.0;
    *perimetro = l * 6;
}


int main (void)
{
    float l;
    float a, p;

    printf("Digite o valor do lado do hexagono: ");
    scanf("%f", &l);

    CalculaHexagono(l, &a, &p);

    printf("O valor da area eh: %.1f\n", a);
    printf("O valor do perimetro eh: %.1f\n", p);

    return 0;
}
