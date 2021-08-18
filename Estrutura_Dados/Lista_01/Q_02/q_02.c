#include <stdio.h>

int main() {
    int N;

    printf("Digite um numero inteiro: ");
    scanf("%d", &N);

    if(N % 2 == 0) {
        printf("%d é par!\n", N);
    }else {
        printf("%d é impar!\n", N);
    }

    return 0;
}