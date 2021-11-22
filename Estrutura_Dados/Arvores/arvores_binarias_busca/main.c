#include <stdio.h>
#include "arvores_binarias_busca.h"

int main() {
    Arv *arv;
    ArvNo *no;
    int n1, n2, n3, n4;
    n1 = 10;
    n2 = 20;
    n3 = 30;
    n4 = 5;

    // Criar
    arv = arv_cria();

    // Inserir
    arv_insere(arv, n1);
    arv_insere(arv, n2);
    arv_insere(arv, n2);
    arv_insere(arv, n3);
    arv_insere(arv, n4);

    // Buscar
    
    no = arv_busca(arv, n1);
    if(no)
        printf("Valor %d existe na arvore!\n", n1);
    else
        printf("Valor %d não existe na arvore!\n", n1);

    no = arv_busca(arv, n2);
    if(no)
        printf("Valor %d existe na arvore!\n", n2);
    else
        printf("Valor %d não existe na arvore!\n", n2);

    // Remover

    arv_remove(arv, n2);
    no = arv_busca(arv, n2);
    if(no)
        printf("Valor %d existe na arvore!\n", n2);
    else
        printf("Valor %d não existe na arvore!\n", n2);

    // Liberar

    arv_libera(arv);

    return 0;
}