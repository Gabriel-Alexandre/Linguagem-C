#include <stdio.h>

int main (void)
{
    float nota1, nota2, nota3;
    int media;

    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3.0;

    if (media >= 9)
        puts("Conceito A");
    if (media < 9 && media >= 8)
        puts("Conceito B");
    if (media < 8 && media >= 7)
        puts("Conceito C");
    if (media < 7 && media >= 6)
        puts("Conceito D");
    if (media < 6 && media >= 5)
        puts("Conceito E");
    if (media < 5)
        puts("Conceito F");

    return 0;
}
