#include <stdio.h>

int main (void)
{
    int valor, resto, quant;

    printf("Digite o valor: ");
    scanf("%d", &valor);

    quant = valor / 100;

    if (quant > 0){
    resto = valor % 100;
    printf("%d X 100\n", quant);}

    valor = resto;
    quant = valor / 50;

    if (quant > 0){
    resto = valor % 50;
    printf("%d X 50\n", quant);}

    valor = resto;
    quant = valor / 20;

    if (quant >0){
    resto = valor % 20;
    printf("%d X 20\n", quant);}

    valor = resto;
    quant = valor / 10;

    if (quant > 0){
    resto = valor % 10;
    printf("%d X 10\n", quant);}

    valor = resto;
    quant = valor / 5;

    if (quant > 0){
    resto = valor % 5;
    printf("%d X 5\n", quant);}

    valor = resto;
    quant = valor / 2;

    if (quant > 0){
    resto = valor % 2;
    printf("%d X 2\n", quant);}

    valor = resto;
    quant = valor / 1;

    if (quant > 0){
    resto = valor % 1;
    printf("%d X 1\n", quant);}


    return 0;
}
