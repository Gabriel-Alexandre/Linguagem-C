#ifndef _FILA_C_
#define _FILA_C_
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct queue {
    No *inicio;
    No *fim;
};

// Padrão de retorno:

// return -1: Erro de criação da pilha
// return 0: Erro de execução da função
// return 1: Sucesso na execução da função 

struct no {
    No *prox;
    No *ant;
    char v;
};

Queue *create_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if(queue != NULL) {
        // fila vazia
        // tanto inicio como o fim apontam para nulo
        queue->inicio = NULL;
        queue->fim = NULL;
    }

    return queue;
}

// Insere elemento no fim
int insert_queue(Queue *queue, int valor) {
    if(queue == NULL)
        return -1;
    
    No *no = (No *) malloc(sizeof(No));

    if(no == NULL)
        return -1;
    
    no->v = valor;
    no->prox = NULL;

    // fila vazia
    if(isEmpty_queue(queue)) {
        queue->inicio = no; // tanto o inicio como o fim recebem o nó
        no->ant = NULL;
    } else {
        queue->fim->prox = no; // próximo de fim aponta para o nó criado
        no->ant = queue->fim; // anterior do no criado aponta para o fim
    }

    queue->fim = no; // nó criado se torna o fim

    return 1;
}

// Remove elemento do inicio
int remove_queue(Queue *queue) {
    if(queue == NULL)
        return -1;
    
    if(isEmpty_queue(queue)) // fila vazia
        return 0;
    
    No *aux = queue->inicio; 
    queue->inicio = queue->inicio->prox; // inicio aponta para seu próximo elemento

    if(queue->inicio == NULL) // A fila ficou vazia 
        queue->fim = NULL; // Inicio e fim apontam para nulo
    else
        queue->inicio->ant = NULL; // anterior de inicio aponta para NULL

    free(aux);

    return 1;
}

int consult_queue(Queue *queue, char *valor) {
    if(queue == NULL)
        return -1;
    
    if(isEmpty_queue(queue))
        return 0;

    *valor = queue->inicio->v;

    return 1;
}

int size_queue(Queue *queue) {
    if(queue == NULL) 
        return -1;
    
    No *aux = queue->inicio;
    int cont = 0;

    // Conta até o atributo próximo de inicio ser nulo
    while(aux != NULL) {
        cont++;
        aux = aux->prox;
    }

    return cont;
}

int isEmpty_queue(Queue *queue) {
    if(queue == NULL)
        return -1;
    if(queue->inicio == NULL && queue->fim == NULL) 
        return 1;
    
    return 0;
}

void clear_queue(Queue *queue) {
    if(queue != NULL) {
        No *aux;

        // libera até o atributo próximo de inicio ser nulo
        while(queue->inicio != NULL) {
            aux = queue->inicio;
            queue->inicio = queue->inicio->prox;
            free(aux);
        }
        
        free(queue);
    }
}

#endif