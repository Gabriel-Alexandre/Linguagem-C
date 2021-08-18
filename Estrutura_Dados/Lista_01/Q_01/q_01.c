#include <stdio.h>

int main() {
    float raio;
    float area;


    printf("Raio: ");
    do {
        scanf("%f", &raio);
        if(raio <= 0) {
            printf("Digite um valor valido!\nRaio: ");
        }
    }while(raio <= 0);

    area = (raio * raio) * 3.14;

    printf("Area do circulo: %.2f\n", area);

    return 0;
}