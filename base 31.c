#include <stdio.h>

int main (void)
{
    int numero;
    int resto;
    int contador1 = 3;
    int contador2 = 4;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 2){
        printf("%d nao eh primo", numero);
        return 1;}
    if (numero == 2){
        printf("%d eh primo", numero);
        return 2;}

    while (contador1 <= numero)
    {
        resto = numero % contador1;

        if ((resto == 0) && (contador1 < numero)){
            printf("%d nao eh primo", numero);
            return 3;}
        if ((resto != 0) && (contador2 == numero)){
            printf("%d nao eh primo", numero);
            return 5;}
        else if ((resto == 0) && (contador1 == numero)){
            printf("%d eh primo", numero);
            return 4;}

        contador1 = contador1 + 2;
        contador2 = contador2 + 2;
    }

    return 0;
}
