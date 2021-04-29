#include <stdio.h>

int main (void)

{
    float peso,altura,imc;

    printf("Informe seu peso: ");
    scanf("%f", &peso);
    printf("Informe sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura*altura);

    printf("O seu IMC eh: %.2f", imc);

    return 0;
}
