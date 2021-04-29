#include <stdio.h>

int main (void)

{
    float nota1, nota2, nota3, nota4, mediaP;

    printf("Informe sua primeira nota: ");
    scanf("%f", &nota1);
    printf("Informe sua segunda nota: ");
    scanf("%f", &nota2);
    printf("Informe sua terceira nota: ");
    scanf("%f", &nota3);
    printf("Informe sua quarta nota: ");
    scanf("%f", &nota4);

    mediaP = (nota1 * 1 + nota2 * 2 + nota3 * 3 + nota4 * 4) / 10;

    printf("Sua media ponderada eh: %.1f", mediaP);

    return 0;
}
