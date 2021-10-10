#include <stdio.h>
#include <stdlib.h>

void invert(const int *origem, int *destino, int indice) {
    for(int i = indice-1, j = 0; i >= 0, j <= indice-1; i--, j++){
        destino[j] = origem[i];
    }
}

int main() {
    const int origem[5] = {0, 1, 2, 3, 4};
    int destino[5];

    invert(origem, destino, 5);

    for (int i = 0; i < 5; i++){
        printf("[%d] = %d\n", i ,destino[i]);
    }

    return 0;
}