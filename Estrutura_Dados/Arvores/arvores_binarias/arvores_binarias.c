#ifndef _ARVORESBINARIAS_C_
#define _ARVORESBINARIAS_C_
#include <stdio.h>
#include <stdlib.h>
#include "arvores_binarias.h"

// Implementação diferente do professor

// Essa implementação serviu como base para eu entender como funciona uma arvore binária e como posso implementar 
// algumas funções de maneira diferente, porém se for necessário implementar um arvore binária usar o TAD do professor
// adicionando as devidas especificidades de cada questão. (Qualquer coisa se precisar implementar mais funções, posso 
// usar esse meu TAD como referência).

// Padrão de retorno:

// return -1: Erro de criação da pilha
// return 0: Erro de execução da função
// return 1: Sucesso na execução da função

// Para arvores binárias a lógica de percorrer recursivamente a arvore é a mesma, o que muda é a ordem que é percorrida entre: raiz, direta e esquerda.
// A ordem que a arvore percorrida importa bastante, a melhor ordem de percorrer varia de caso para caso, por exemplo: Foi escolhido a ordem de
// percorrer posOrdem para liberação da arvore, pois essa forma garante e uma operação só será realizada no nó raiz depois que a operação for realizada
// nos nóis da esquerda e direita.
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

int estaVazia_arv(No* raiz) {
    if(raiz == NULL) 
        return -1;
    if(*raiz == NULL) 
        return 1; // Arvore vaiza

    return 0;
}

int altura_arv(No* raiz) {
    if(raiz == NULL) 
        return -1;
    if(*raiz == NULL) 
        return 0; // Arvore vaiza
    
    int alt_esq = altura_arv(((*raiz)->esq)); // Percorre recursivamente o nó a esquerda
    int alt_dir = altura_arv(((*raiz)->dir)); // Percorre recursivamente o nó a direita
    if(alt_esq > alt_dir) // Dependendo de qual for a altura maior, é realizado a soma e no final é retornado a altura da arvore
        return (alt_esq + 1);
    else
        return (alt_dir + 1);

    // O funcionamento da função pode ser descrito como: A função vai percorrer recursivamente todos os nóis da esquerda até retorna zero (nó folha),
    // depois vai percorrer recursivamente o nó da direita filho do mesmo pai, realizar o mesmo processo de percorre recursivamente esquerda e direita
    // caso tenha nó filho, depois vai comporar a altura que foi retornada em cada nó, e dependendo de qual for a altura maior, a função irá somar 1 a
    // altura da esqueda ou direita. É importante observar que a comparação e soma vai ocorrer sempre depois de analisar os dois nóis, pois quando
    // a função retoma sua execução de uma chamada recursiva, ela retoma do mesmo ponto de onde parou.    

    // O fluxo de execução pode ser melhor entendido através de um gráfico.
}

int totalNo_arv(No* raiz) {
    if(raiz == NULL) 
        return -1;
    if(*raiz == NULL) 
        return 0; // Arvore vaiza

    int alt_esq = altura_arv(((*raiz)->esq)); // Percorre recursivamente o nó a esquerda
    int alt_dir = altura_arv(((*raiz)->dir)); // Percorre recursivamente o nó a direita
    return(alt_esq + alt_dir + 1); // Retorna a quantidade total de nóis

    // O funcionamento da função pode ser entendido de maneira semelhante a função "altura_arv()".

    // O fluxo de execução pode ser melhor entendido através de um gráfico.
}

void preOrdem_arv(No* raiz) {
    if(raiz == NULL) 
        return;
    
    if(*raiz != NULL) {
        printf("%d\n", (*raiz)->valor); // printa o valor do nó
        preOrdem_arv(((*raiz)->esq)); // Percorre recursivamente o nó a esquerda
        preOrdem_arv(((*raiz)->dir)); // Percorre recursivamente o nó a direita
    }
}

void emOrdem_arv(No* raiz) {
    if(raiz == NULL) 
        return;
    
    if(*raiz != NULL) {
        emOrdem_arv(((*raiz)->esq)); // Percorre recursivamente o nó a esquerda
        printf("%d\n", (*raiz)->valor); // printa o valor do nó
        emOrdem_arv(((*raiz)->dir)); // Percorre recursivamente o nó a direita
    }
}

void posOrdem_arv(No* raiz) {
    if(raiz == NULL) 
        return;
    
    if(*raiz != NULL) {
        emOrdem_arv(((*raiz)->esq)); // Percorre recursivamente o nó a esquerda
        emOrdem_arv(((*raiz)->dir)); // Percorre recursivamente o nó a direita
        printf("%d\n", (*raiz)->valor); // printa o valor do nó
    }
}

// lembrar que "No" já é um ponteiro, então nesse caso eu também estou recebendo um endereço de memoria.
static void libera_no(No *no) {
    if(no == NULL)
        return;
    
    libera_no((*no)->esq); // Percorre recursivamente o nó a esquerda
    libera_no((*no)->dir); // Percorre recursivamente o nó a direita
    free(no); // Depois que percorrer libera o nó
    no = NULL; // Evita erro de verificação

    // Depois que o nó for liberado e a função terminar, a execução retorna a execução da função anterior a ela, isso acontece porque a liberação
    // está acontecendo de maneira recursiva, e como a chamada de uma nova função funciona como uma pilha, isso significa que quando uma função
    // termina sua execução, ela retorna para a última chamada de função a partir do ponto onde parou. Para esse algorítmo, isso garante que todos
    // os nóis da arvore serão liberados.
    
    // O fluxo de liberação pode ser melhor entendido através de um gráfico.
}

void libera_arv(No* raiz) {
    if(raiz == NULL)
        return;
    
    libera_no(&*raiz); // percorre a arvore e libera todos o nóis
    free(raiz); // libera a raiz
}


#endif