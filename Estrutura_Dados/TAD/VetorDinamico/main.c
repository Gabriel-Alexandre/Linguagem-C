#include <stdio.h>
#include "vetorDinamico.h"

int main(void) {

    VetorDinamico *vetor;
    float inserir, aux;
    int n, op, tamanho_vetorV;

    printf("Deseja um vetor de que dimensão: ");
    scanf("%d", &n);

    vetor = criaVetor(n);

    printf("Insira um numero: ");

    while(scanf("%f", &inserir)) {

        if(inserir == 0)
            break;
        
        insere_vetor(vetor, inserir);

        printf("Se deseja visualizar o vetor digite (1): ");
        scanf("%d", &op);

        if(op == 1) {
            tamanho_vetorV = tamanho_vetor(vetor);
            
            for(int i = 0; i < tamanho_vetorV; i++) {
                acessa_vetor(vetor, i, &aux);
                printf("\n");
                printf("%.1f  ", aux);
            }

            printf("\nTamanho: %d\n\n", tamanho_vetorV);
            printf("Insira um numero ou (0): ");
        }
    }

    libera_vetor(vetor);

    return 0;
}