#include <stdio.h>

int main() {
    int base, altura;

    printf("Insira a base (em cm): ");
    scanf("%d", &base);

    printf("Insira a altura (em cm): ");
    scanf("%d", &altura);

    printf("Area: %d\n", base * altura);
    printf("Perimetro: %d\n", 2*base + 2*altura);

    return 0;
}