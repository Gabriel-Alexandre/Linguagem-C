#include <stdio.h>
#include <math.h>

int main (void)

{
    float a, b, c;
    float delta;
    float x1, x2;

    printf("Digite o valor do coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o valor do coeficiente b: ");
    scanf("%f", &b);
    printf("Digite o valor do coeficiente c: ");
    scanf("%f", &c);

    delta = (b*b) - (4 * a * c);
    x1 = (-b - sqrt(delta)) / 2 * a;
    x2 = (-b + sqrt(delta)) / 2 * a;

    printf("Com os coeficientes\na = %.1f\nb = %.1f\nc = %.1f\n", a,b,c);
    printf("As raizes da equacao serao: %.1f e %.1f", x1,x2);

    return 0;
}
