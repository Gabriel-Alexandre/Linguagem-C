#include <stdio.h>

// Arvores AVL

// Definição da estrutura
typedef struct arv Arv;
typedef struct arvno ArvNo;

struct arv {
    ArvNo* raiz;
};

struct arvno {
    int info;
    int alt; // altura da sub-árvore
    ArvNo* esq;
    ArvNo* dir;
};

// Operações auxiliares

// Calcula altura de um nó
int altura_no(ArvNo* raiz) {
    // Se o nó não existe, sua altura é -1
    if(raiz == NULL) return -1;
    // Retorna altura do nó
    else return raiz->alt;
}

// Calcula o fator de balanceamento de um nó
int fatorBalanceamento_no(ArvNo* raiz) {
    // retorna a diferença em módulo
    return labs(altura_no(raiz->esq) - altura_no(raiz->dir)); 
}

// Procura pela sub-árvore mais a esquerda
ArvNo *procuraMenorEsq(ArvNo *atual) {
    ArvNo *no1 = atual;
    ArvNo *no2 = atual->esq;

    while(no2 != NULL) {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1; 
}

// Calcula maior valor
int maior(int x, int y) {
    if(x > y) return x;
    else return y;
}