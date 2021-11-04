#include <stdio.h>

int main() {
    int aux;

    printf("Digite um número: ");
    scanf("%d", &aux);

    for(int i = 1; i < 10; i++) {
        printf("%d X %d = %d\n", i, aux, i*aux);
    }

    return 0;
}