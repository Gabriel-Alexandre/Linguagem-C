#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c;
    int **mat;

    // Alocação dinâmica de matriz

    printf("Numero de linhas: ");
    scanf("%d", &l);
    printf("Numero de colunas: ");
    scanf("%d", &c);

    mat = malloc(l * sizeof(int*));

    for(int i = 0; i < l; i++) {
      mat[i] = (int *) malloc(c * sizeof(int));
    }

    // Preferir usar o for aninhado a usar o for com mais de uma variável de contagem.
    // O Segundo tipo da problema em alguns casos, então é melhor evitar.

    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++) {
        mat[i][j] = 0;
      }
    }

    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++) {
        printf("%d ", mat[i][j]);
        
        if(j == c-1) {
          printf("\n");
        }
      }
    }

    for(int i = 0; i < l; i++) {
      free(mat[i]);
    }
    free(mat);
    return 0;
}