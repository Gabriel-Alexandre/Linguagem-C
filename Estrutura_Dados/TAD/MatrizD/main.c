#include <stdio.h>
#include "matrizD.h"

int main(void) {

    int l, c;
    float v;
    MatrizD *m;

    printf("Linhas: ");
    scanf("%d", &l);
    
    printf("Colunas: ");
    scanf("%d", &c);

    m = criaMatrizD(l, c);

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            atribuiMatrizD(m, i, j, 0.0f);
        }
    }

    printf("Matriz: \n\n");

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            acessaMatrizD(m, i, j, &v);
            printf("%.1f  ", v);
        }
        printf("\n");
    }

    printf("\nnLinhas: %d\n", nlinhas(m));
    printf("nColunas: %d\n", ncolunas(m));

    liberaMatrizD(m);

    return 0;
}