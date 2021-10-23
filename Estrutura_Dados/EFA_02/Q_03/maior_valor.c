#include <stdio.h>
#include <stdlib.h>

int maior_valor(int vetor[], int quant) {
    int maior = 0; // Executa 1 vez

    // Primeira execução, maior é o primeiro elemento
    maior = vetor[0]; // Executa 1 vez

    for(int i = 1; i < quant; i++) { // Executa n vezes
        // Identifica maior, comparando com cada elemento do vetor
        maior = (maior > vetor[i]) ? maior : vetor[i]; // No pior caso Executa (n-1) vezes
    }

    return maior; // Executa 1 vez
}

int main() {
    // Casos de teste
    int vetor[] = {1, 2, 3, 4, 5, 6, 7};
    int vetor1[] = {10, 2, 3, 20, 5, 5, 7};
    int vetor2[] = {0, -2, 30, 4, 25, 6, 31};   
    
    // Imprimindo resultados
    printf("Maior valor: %d\n", maior_valor(vetor, 7));
    printf("Maior valor: %d\n", maior_valor(vetor1, 7));
    printf("Maior valor: %d\n", maior_valor(vetor2, 7));

    return 0;
}