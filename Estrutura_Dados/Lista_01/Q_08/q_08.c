#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &t);

    int *v = (int *) malloc(t*sizeof(int));

    printf("\nEntrada: \n");

    for(int i = 0; i < t; i++) {
        printf("[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nSaida: \n");

    for(int i = 0; i < t; i++) {
        printf("[%d] = %d\n", i, v[i]);
    }

    free(v);

    return 0;
}