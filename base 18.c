#include <stdio.h>

int main (void)
{
    int numero1, numero2, numero3;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &numero3);

    if (numero1 > numero2 && numero1 > numero3){
        printf("%d", numero1);}
    else{
        if (numero2 > numero3){
            printf("%d", numero2);}
        else{
            printf("%d", numero3);}
        }

    return 0;
}
