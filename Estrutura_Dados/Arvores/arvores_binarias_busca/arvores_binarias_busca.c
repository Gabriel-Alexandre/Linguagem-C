#ifndef _ARVORESBINARIASBUSCA_C_
#define _ARVORESBINARIASBUSCA_C_
#include <stdio.h>
#include <stdlib.h>
#include "arvores_binarias_busca.h"

// Padrão de retorno:

// return -1: Arvore não existe
// return 1: Sucesso na execução da função

struct arv {
    ArvNo* raiz;
};

struct arvno {
    int info;
    ArvNo* esq;
    ArvNo* dir;
};

Arv* arv_cria() {
    Arv* arv = (Arv*) malloc(sizeof(Arv)); // Criar árvore

    if(arv != NULL) arv->raiz = NULL; // Nó raiz aponta para NULL

    return arv; // retorna árvore
}

static ArvNo* insere(ArvNo* raiz, int valor) {
    // Se for o nó raiz ou um nó folha, cria um nó com o valor recebido
    if(raiz == NULL) {
        raiz = (ArvNo*) malloc(sizeof(ArvNo));
        
        raiz->info = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    // Se o valor recebido for menor que a raiz, inserir a esquerda
    } else if(valor < raiz->info) 
        raiz->esq = insere(raiz->esq, valor);
    // Se o valor recebido for maior que a raiz, inserir a direita
    else if(valor > raiz->info) 
        raiz->dir = insere(raiz->dir, valor);
    // Se o valor recebido já existe, não inserir novo valor

    return raiz;
}

int arv_insere(Arv* arv, int valor) {
    if(arv == NULL) return -1;
    
    arv->raiz = insere(arv->raiz, valor); // Altera árvore

    return 1;
}

static ArvNo* remover(ArvNo* raiz, int valor) {
    if(raiz == NULL) return NULL;
    else if(raiz->info > valor)
        raiz->esq = remover(raiz->esq, valor); // Percorre recursivamente o nó a esquerda
    else if(raiz->info < valor)
        raiz->dir = remover(raiz->dir, valor); // Percorre recursivamente o nó a direita
    else {
        // Não tem filho
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            raiz = NULL;
        // Um filho a direita
        } else if(raiz->esq == NULL) {
            ArvNo* t = raiz;
            raiz = raiz->dir;
            free(t);
        // Um filho a esquerda
        } else if(raiz->dir == NULL) {
            ArvNo* t = raiz;
            raiz = raiz->esq;
            free(t);
        // Dois filhos
        } else {
            // Identifica sucessor (filho da sub-árvore a esquerda que está mais a direita)
            // Se o filho da sub-árvore a esquerda não tem filho a direita, ela é o sucessor
            ArvNo* f = raiz->esq;
            while(f->dir != NULL) {
                f = f->dir;
            }
            // Seta os valores
            raiz->info = f->info; // O valor do nó é substituido pelo valor do sucessor
            raiz->esq = remover(raiz->esq, valor); // A sub-árvore a esquerda é atualizada
        }
    }
    return raiz;
}

int arv_remove(Arv* arv, int valor) {
    if(arv == NULL) return -1;

    arv->raiz = remover(arv->raiz, valor); // Altera árvore

    return 1;
}

static ArvNo* busca(ArvNo* raiz, int valor) {
    if(raiz == NULL) return NULL; 
    else if(raiz->info > valor) 
        return busca(raiz->esq, valor); // Busca recursivamente o nó a esquerda
    else if(raiz->info < valor) 
        return busca(raiz->dir, valor); // Busca recursivamente o nó a direita
    else return raiz;
}

ArvNo* arv_busca(Arv* arv, int valor) {
    if(arv == NULL) return NULL;

    return busca(arv->raiz, valor); // Retorna endereço do nó que contém a informação do valor recebido
}

static int totalNo(ArvNo *raiz) {
    if(raiz == NULL) return 0;

    int alt_esq = totalNo(raiz->esq); // Percorre recursivamente o nó a esquerda
    int alt_dir = totalNo(raiz->dir); // Percorre recursivamente o nó a direita
    return(alt_esq + alt_dir + 1); // Retorna a quantidade total de nós
}

int arv_totalNo(Arv *arv) {
    if(arv == NULL) return -1;
    if(arv->raiz == NULL) return 0; // Árvore vaiza

    return totalNo(arv->raiz); // Retorna total de nós
}

static int folhas(ArvNo *raiz) {
    if(raiz->esq == NULL && raiz->dir == NULL) {
        return 1; // Se encontrou uma folha, retorna 1
    } else {
        int esquerda =  folhas(raiz->esq); // Percorre recursivamente o nó a esquerda
        int direita = folhas(raiz->dir); // Percorre recursivamente o nó a direita
        return direita + esquerda; // Retorna quantidade de nós folhas 
    }
}

int arv_folhas(Arv* arv) {
    if(arv == NULL) return -1;
    if(arv->raiz == NULL) return 0; // Árvore vaiza
    return (folhas(arv->raiz)); // Retorna total de nós folhas
}

static void mostra(ArvNo *raiz) {
    if(raiz == NULL) return;

    // mostra os valores em pos ordem
    mostra(raiz->esq); // Percorre recursivamente o nó a esquerda
    mostra(raiz->dir); // Percorre recursivamente o nó a direita
    printf("%d\n", raiz->info); // printa o valor do nó
}

void arv_mostra(Arv* arv) {
    if(arv == NULL || arv->raiz == NULL) // Árvore não existe ou está vazia
        return;
    
    mostra(arv->raiz); // Mostra os valores da árvore
}

static void libera(ArvNo* raiz) {
    if(raiz != NULL) {
        libera(raiz->esq); // Percorre recursivamente o nó a esquerda
        libera(raiz->dir); // Percorre recursivamente o nó a direita
        free(raiz); // Libera nó
    }
}

void arv_libera(Arv* arv) {
    if(arv == NULL) return;

    libera(arv->raiz); // Libera nós
    free(arv); // Libera árvore
}

#endif
