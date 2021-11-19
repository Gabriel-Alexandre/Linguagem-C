#ifndef _ARVORESBINARIAS_C_
#define _ARVORESBINARIAS_C_
#include <stdio.h>
#include <stdlib.h>
#include "arvores_binarias.h"

// Padrão de retorno:

// return -1: Erro de criação da arvore
// return 0: Erro de execução da função
// return 1: Sucesso na execução da função

struct no {
    int valor;
    No* esq;
    No* dir;
};

No* cria_arv() {
    No* raiz = (No*) malloc(sizeof(No)); // Cria o nó raiz

    // Como o tipo "No" já é um ponteiro, "raiz" se torna um ponteiro de ponteiro, assim sendo:
    // (raiz) -> representa o endereço do ponteiro que aponta para o nó raiz.
    // (*raiz) -> representa o endereço do nó que está representando o nó raiz.

    // Diferente dos outros nóis, que são ligados a arvore a partir de um nó pai apontando para a esquerda ou direita, 
    // o nó raiz possui um variável que guarda seu endereço, desse maneira o nó raiz pode ser alterado mais 
    // facilmente quando necessário.

    if(raiz != NULL) 
        raiz = NULL; // Aponta para nulo

    return raiz;
}

// lembrar que "No" já é um ponteiro, então nesse caso eu também estou recebendo um endereço de memoria.
void libera_no(No no) {
    if(no == NULL)
        return -1;
    
    libera_no(no->esq); // Percorre recursivamente o nó a esquerda
    libera_no(no->dir); // Percorre recursivamente o nó a direita
    free(no); // Depois que percorrer libera o nó
    no = NULL; // Evita erro de verificação

    // Depois que o nó for liberado e a função terminar, a execução retorna a execução da função anterior a ela, isso acontece porque a liberação
    // está acontecendo de maneira recursiva, e como a chamada de uma nova função funciona como uma pilha, isso significa que quando uma função
    // termina sua execução, ela retorna para a última chamada de função a partir do ponto onde parou. Para esse algorítmo, isso garante que todos
    // os nóis da arvore serão liberados.
    
    // O fluxo de liberação pode ser melhor entendido através de um gráfico
}

void libera_arv(No* raiz) {
    if(raiz == NULL)
        return -1;
    
    libera_no(*raiz); // percorre a arvore e libera todos o nóis
    free(raiz); // libera a raiz
}


#endif