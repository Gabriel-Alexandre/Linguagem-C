#include <stdio.h>
#include "arvores_binarias_busca.h"
#define QUANT_TEST 10

int main() {
    Arv *arv;
    ArvNo *no;
    int inserir[QUANT_TEST] = {10, 10, 30, 35, 6, 4, 12, 50, 50, 60}; // Total de números únicos: 8
    int buscar[QUANT_TEST] = {10, 20, 30, 5, 6, 100, 12, 50, 45, 60};

    // Criar
    arv = arv_cria();

    // Inserir
    printf("Inserindo elementos... [INICIO]\n");
    for(int i = 0; i < QUANT_TEST; i++) {
        arv_insere(arv, inserir[i]);
    }
    printf("Inserindo elementos... [FIM]\n\n");

    // Buscar
    printf("Buscando elementos... [INICIO]\n");
    for(int i = 0; i < QUANT_TEST; i++) {
        no = arv_busca(arv, buscar[i]);

        if(no) printf("Valor %d existe na arvore!\n", buscar[i]);
        else printf("Valor %d não existe na arvore!\n", buscar[i]);
    }
    printf("Buscando elementos... [FIM]\n\n");

    // Remover
    printf("Removendo elemento 30\n");
    int r = 30;
    arv_remove(arv, r);
    printf("Buscando elemento 30 [INICIO]\n");
    no = arv_busca(arv, r);
    if(no) printf("Valor %d existe na arvore!\n", r);
    else printf("Valor %d não existe na arvore!\n", r);
    printf("Buscando elemento 30 [FIM]\n\n");
    
    // Total de nós
    int totalno = arv_totalNo(arv);
    printf("Total de nóis: %d\n\n", totalno);

    // Mostrar árvore
    printf("Mostrando arvore...\n");
    arv_mostra(arv);

    // Liberar
    arv_libera(arv);

    return 0;
}