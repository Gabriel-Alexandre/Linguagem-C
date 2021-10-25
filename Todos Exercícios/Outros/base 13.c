#include <stdio.h>

int main (void)

{
    int valor, resto, quant;

    printf("Digite o valor desejado: ");
    scanf("%d", &valor);

    quant = valor / 100;
    resto = valor % 100;
    printf("%d x 100\n", quant);

    valor = resto;
    quant = valor / 50;
    resto = valor % 50;
    printf("%d x 50\n", quant);

    valor = resto;
    quant = valor / 20;
    resto = valor % 20;
    printf("%d x 20\n", quant);

    valor = resto;
    quant = valor / 10;
    resto = valor % 10;
    printf("%d x 10\n", quant);

    valor = resto;
    quant = valor / 5;
    resto = valor % 5;
    printf("%d x 5\n", quant);

    valor = resto;
    quant = valor / 2;
    resto = valor % 2;
    printf("%d x 2\n", quant);

    valor = resto;
    quant = valor / 1;
    resto = valor % 1;
    printf("%d x 1\n", quant);

    return 0;
}
