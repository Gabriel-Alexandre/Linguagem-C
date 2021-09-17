#include "definicao.h"
#include <stddef.h>
#include <stdlib.h>

struct no {
    Elemento info;
    No *proximo;
};

void criar_lista(No **lista) {
    *lista = NULL;
}

No *ll_create_no(int info) {
    No *no = (No*) malloc(sizeof(No));

    if(no) {
        no->info = info;
        no->proximo = NULL;
    }

    return no;
}


// retorna 1 em caso de sucesso e 0 caso contrário.
int ll_insert_first(No **lhead, int info) {
    // cria um nó novo a ser inserido na lista com a informação fornecida.
    No *novo = (No*) malloc(sizeof(No));
    //verifica se o nó foi de fato criado.
    if(novo == NULL)
        return 0;
    
    novo->info = info;

    // faz o atributo próximo do nó criado apontar para o nó que antes era o primeiro da lista.
    novo->proximo = *lhead;
    //faz o nó inicial receber o endereço do nó criado, tornando-o o primeiro nó da lista.
    *lhead = novo;
    return 1;
}

// retorna 1 em caso de sucesso e 0 caso contrário.
int ll_insert_last(No **lhead, int info) {
    // cria um nó novo a ser inserido na lista com a informação fornecida.
    No *novo = (No*) malloc(sizeof(No));
    //verifica se o nó foi de fato criado.
    if(novo == NULL) {
        return 0;
    }

    novo->info = info;

    // identifica o último elemento.
    No *ultimo = *lhead;
    while(ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }

    // faz o atributo próximo de último nó apontar para o nó criado.
    ultimo->proximo = novo;
    // faz o nó criado apontar para nulo, tornando-o último da lista.
    novo->proximo = NULL;

    return 1;
}

// retorna 1 em caso de sucesso e 0 caso contrário.
int ll_insert_half(No **lhead, int info, int i) {
    // cria um nó novo a ser inserido na lista com a informação fornecida.
    No *novo = (No*) malloc(sizeof(No));
    //verifica se o nó foi de fato criado.
    if(novo == NULL) {
        return 0;
    }

    novo->info = info;

    // identificar o elemento anterior a posição que pedida
    No *anterior = *lhead;
    for(int j = 0; j < i; j++) {
        anterior = anterior->proximo;
    }

    // faz o atributo próximo do nó criando apontar para 
    // o atributo próximo do no anterior.
    novo->proximo = anterior->proximo;
    // faz o atributo próximo do nó anterior, apontar para o nó criado.
    anterior->proximo = novo;
}

