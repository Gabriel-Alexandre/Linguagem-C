#include <stdio.h>

int main (void)
{
    float a, b, c;
    float delta, x1, x2;

    printf("Digite o coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o coeficiente b: ");
    scanf("%f", &b);
    printf("Digite o coeficiente c: ");
    scanf("%f", &c);

    if (a == 0){
        printf("Os coeficientes nao formam uma equacao do segundo grau\n");

        return 1;}

    delta = (b * b) - (4 * a * c);

    if (delta < 0){
        printf("A equacao nao possui raizes reais\n");

        return 2;}

    x1 = (-b - sqrt(delta)) / 2 * a;
    x2 = (-b + sqrt(delta)) / 2 * a;

    if (delta == 0){
        printf("A equacao possui apenas uma raiz\n");
        printf("A raiz da equacao eh: %f\n", x1);}

    if (delta >0){
        printf("As raizes da equacao sao: %f e %f\n", x1,x2);}

    return 0;
}
