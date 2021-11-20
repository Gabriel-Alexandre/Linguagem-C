#include <stdio.h>
#include "arvores_binarias.h"

int main() {
    Arv* arv;
    ArvNo *a, *b, *c, *d, *e;

    // Cria
    e = arv_criano('E', NULL, NULL);
    d = arv_criano('D', NULL, NULL);
    c = arv_criano('C', NULL, NULL);
    b = arv_criano('B', d, e);
    a = arv_criano('A', b, c);
    arv = arv_cria(a);

    // Imprime
    arv_imprime(arv);

    // Verifica se pertence
    char carc = 'G';
    if(arv_pertence(arv, carc))
        printf("\n[%c] pertence a arvore\n", carc);
    else
        printf("\n[%c] não pertence a arvore\n", carc);

    // Verifica altura
    printf("A altura da arvore é %d\n", arv_altura(arv));

    // Libera 
    arv_libera(arv);

    return 0;
}