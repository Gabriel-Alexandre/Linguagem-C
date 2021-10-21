#include <stdio.h>
#define TAM_TEST 8

int resolve_mdc(int a, int b) {
    if(b == 0) return a;

    // Se "b" for negativo, inverte o sinal de "b"
    if(b < 0) return resolve_mdc(a, -b);

    // se "b" for maior que "a", "b" vira "a" e "a" vira "b"
    // se "b" for igual a zero, a função retorna "a" na próxima chamada
    // se "a" for maior que "b", continua a buscando o MDC
    if(b > 0) return resolve_mdc(b, a % b);
}

int main() {
    // Casos de teste
    int a1[TAM_TEST] = {528, 240, 120, 20, 18, 8, 18, 18};
    int b1[TAM_TEST] = {240, 528, 36, 24, 60, 12, 0, -60};

    // Imprimindo resultados
    for(int i = 0; i < TAM_TEST; i++) {
        printf("MDC de %d e %d é: %d\n", a1[i], b1[i], resolve_mdc(a1[i],b1[i]));
    }

    return 0;
}