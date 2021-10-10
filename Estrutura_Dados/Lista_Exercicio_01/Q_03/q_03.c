#include <stdio.h>

int main(void) {
    float nota[3];
    float soma = 0, media, recup;

    for(int i=0; i<3; i++) {
        printf("Nota [%d]: ", i+1);
        scanf("%f", &nota[i]);
        soma = soma + nota[i];
    }

    media = soma/3;
    recup = 28 - soma;

    if(media >= 7){
        printf("Aprovado!, Media: %.2f\n", media);
    }else if(media >= 4 && media < 7) {
        printf("Recuperacao!, Media: %.2f\n", media);
        printf("Você precisa de %.2f para ser Aprovado!\n", recup);
    }else {
        printf("Reprovado!, Media: %.2f\n", media);
    }

    return 0;
}