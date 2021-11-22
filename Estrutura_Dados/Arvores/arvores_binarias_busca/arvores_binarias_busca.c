#ifndef _ARVORESBINARIASBUSCA_C_
#define _ARVORESBINARIASBUSCA_C_
#include <stdio.h>
#include <stdlib.h>
#include "arvores_binarias_busca.h"

// Padrão de retorno:

// return -1: Arvore não existe
// return 1: Sucesso na execução da função

// Arvore binária de busca só aceita valores únicos ?
// Seria bom eu adicionar código de erro nas funções ?

// Em caso de valores repetidos, buscar não fazer uma nova alocação dinâmica, pois
// seguindo a implementação até agora, a alocação é realizada mesmo quando o valor informado é
// repetido.

struct arv {
    ArvNo* raiz;
};

struct arvno {
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

Arv* arv_cria() {
    Arv* arv = (Arv*) malloc(sizeof(Arv)); // Criar arvore

    if(arv != NULL)
        arv->raiz = NULL; // Nó raiz aponta para NULL

    return arv; // retorna arvore
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
    if(arv == NULL)
        return -1;
    
    arv->raiz = insere(arv->raiz, valor); // Altera arvore

    return 1;
}

static ArvNo* remover(ArvNo* raiz, int valor) {
    if(raiz == NULL) 
        return NULL;
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
            // Identifica sucessor (filho da subarvore a esquerda que está mais a direita)
            // Se o filho da subarvore a esquerda não tem filho a direita, ela é o sucessor
            ArvNo* f = raiz->esq;
            while(f->dir != NULL) {
                f = f->dir;
            }
            // Seta os valores
            raiz->info = f->info; // O valor do nó é substituido pelo valor do sucessor
            raiz->esq = remover(raiz->esq, valor); // A subarvore a esquerda é atualizada
            // A subarvore a direita permanece com a mesma estrutura
        }
    }

    return raiz;
}

int arv_remove(Arv* arv, int valor) {
    if(arv == NULL)
        return -1;

    arv->raiz = remover(arv->raiz, valor); // Altera arvore

    return 1;
}

static ArvNo* busca(ArvNo* raiz, int valor) {
    if(raiz == NULL) 
        return NULL; 
    else if(raiz->info > valor) 
        return busca(raiz->esq, valor); // Busca recursivamente o nó a esquerda
    else if(raiz->info < valor) 
        return busca(raiz->dir, valor); // Busca recursivamente o nó a direita
    else 
        return raiz;
}

ArvNo* arv_busca(Arv* arv, int valor) {
    if(arv == NULL)
        return NULL;

    return busca(arv->raiz, valor); // Retorna endereço do nó compatível com o valor recebido
}

static void libera(ArvNo* raiz) {
    if(raiz != NULL) {
        libera(raiz->esq); // Percorre recursivamente o nó a esquerda
        libera(raiz->dir); // Percorre recursivamente o nó a direita
        free(raiz); // Libera nó
    }
}

void arv_libera(Arv* arv) {
    if(arv == NULL) 
        return;

    libera(arv->raiz); // Libera nóis
    free(arv); // Libera arvore
}

#endif


/*
- Próximos passos:

1- Entender e comentar funções implementadas. (OK)
2- Testar funções implementadas.
3- Implementar e comentar funções que faltam.
4- Testar funções implementadas.
5- Começar a escrever resposata da questão 1.
6- Ajudar Anderson no que for necessário.
7- Estudar e implementar arvores AVL.
8- Estudar e implementar grafos.

*/