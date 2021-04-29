#include <stdio.h>

int main (void)

{

    int base, altura;
    float area;

    printf("Digite o valor inteiro da base: ");
    scanf("%d", &base);
    printf("Digite o valor inteiro da altura: ");
    scanf("%d", &altura);

    area = (base * altura)/2;

    printf("A area do triangulo eh: %f", area);

    return 0;
}
