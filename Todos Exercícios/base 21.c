#include <stdio.h>


int main (void)
{
    float peso, altura, imc;

    printf("Digite seu peso: ");
    scanf("%f", &peso);
    printf("Digite sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    if (imc <= 18.5){
        printf("Baixo peso");}
    if (imc > 18.5 && imc <= 25){
        printf("Normal");}
    if (imc >25 && imc <= 30){
        printf("Sobrepeso");}
    if (imc > 30){
        printf("Obesidade");}

    return 0;
}
