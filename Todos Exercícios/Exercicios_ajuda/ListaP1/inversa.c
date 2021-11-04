#include <stdio.h>
#define TAM_VETOR 6

int main() {
    int vetor[TAM_VETOR];

    for(int i = 0; i < TAM_VETOR; i++) {
        printf("[%d] = ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\n");

    for(int i = TAM_VETOR - 1; i > -1; i--) {
        printf("[%d]", vetor[i]);
    }

    printf("\n");

    return 0;
}

/*

tabuada - 2
retangulo - 3
idade - 4
idade2 - 5
inversa - 9

*/