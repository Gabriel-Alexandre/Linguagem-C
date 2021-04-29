#include <stdio.h>

int main (void)
{
    char sexo;
    float altura;

    printf("Digite seu sexo: ");
    scanf("%c", &sexo);
    printf("Digite sua altura: ");
    scanf("%f", &altura);

    if (sexo == 'm'){
        printf("Seu peso ideal eh: %f", ((72.7 * altura) - 58));}
    else {
        printf("Seu peso ideal eh: %f", ((62.1 * altura) - 44.7));}


    return 0;
}
