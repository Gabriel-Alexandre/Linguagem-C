#ifndef _ARVORESBINARIAS_C_
#define _ARVORESBINARIAS_C_
#include <stdio.h>
#include <stdlib.h>
#include "arvores_binarias.h"

// Implementação do professor de umamArvore binária.

struct arv {
    ArvNo* raiz;
};

struct arvno {
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

Arv* arv_cria(ArvNo* r) {
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    arv->raiz = r;

    return arv;
}

ArvNo* arv_criano(char c, ArvNo* esq, ArvNo* dir) {
    ArvNo* n = (ArvNo*) malloc(sizeof(ArvNo));

    n->info = c;
    n->esq = esq;
    n->dir = dir;

    return n;
}

static void libera(ArvNo* r) {
    if(r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void arv_libera(Arv* arv) {
    libera(arv->raiz);
    free(arv);
}

static void imprime(ArvNo* r) {
    if(r != NULL) {
        printf("%c", r->info);
        imprime(r->esq);
        imprime(r->dir);
    }
}

void arv_imprime(Arv* arv) {
    imprime(arv->raiz);
}

static int pertence(ArvNo* r, char c) {
    if(r == NULL)
        return 0;
    else
        return c==r->info ||
            pertence(r->esq, c) ||
            pertence(r->dir, c);
}   

int arv_pertence(Arv* arv, char c) {
    return pertence(arv->raiz, c);
}

static int max2(int a, int b) {
    return (a > b) ? a : b;
}

static int altura(ArvNo* r) {
    if(r == NULL)
        return -1;
    else
        return 1 + max2(altura(r->esq), altura(r->dir));
}

int arv_altura(Arv* arv) {
    return altura(arv->raiz);
}

#endif