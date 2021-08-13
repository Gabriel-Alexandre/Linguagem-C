#include <stdio.h>

void question() {
    printf("Digite um numero: ");
}

int number(int n) {
    printf("O numero digitado foi: %d\n", n);
}

int main() {
    int N;

    question();
    scanf("%d", &N);
    number(N);

    return 0;
}