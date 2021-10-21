#include <stdio.h>
#include <stdlib.h>

int maior_valor(int vetor[], int quant) {
    int maior = 0;

    for(int i = 0; i < quant; i++) {
        // Primeira execução, maior é o primeiro elemento
        if(i == 0)
            maior = vetor[i];
        
        // Identifica maior, comparando com cada elemento do vetor
        maior = (maior > vetor[i]) ? maior : vetor[i];
    }

    return maior;
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