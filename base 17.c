#include <stdio.h>

int main (void)
{
    float numero1, numero2;

    printf("Digite o primeiro numero: ");
    scanf("%f", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%f", &numero2);

    if (numero1 > numero2){
        printf("%.1f\n", numero2);}
    else{
        if(numero1 == numero2){
            printf("O numeros sao iguais");}
        else{
            printf("%.1f", numero1);}
        }

    return 0;
}
