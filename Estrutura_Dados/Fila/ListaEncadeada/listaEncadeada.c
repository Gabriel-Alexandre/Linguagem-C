#ifndef _LISTAENCADEADA_C_
#define _LISTAENCADEADA_C_
#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// Nesse caso, o sentido de implementação é diferente do sentido real da fila.

struct queue {
    No *inicio;
    No *fim;
};

// Eu poderia criar um elemento "int quantidade", para manipular durante a inserção, dessa maneira 
// na função de tamanho, eu precisaria apenas retornar a quantidade. (Acredito que essa implementação
// seria mais eficiente, mas eu fiz da maneira mais difícil por fiz didáticos). 

struct no {
    No *prox;
    int v;
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

int insert_queue(Queue *queue, int valor) {
    if(queue == NULL)
        return 0;
    
    No *no = (No *) malloc(sizeof(No));

    if(no == NULL)
        return 0;
    
    no->v = valor;
    no->prox = NULL;

    // fila vazia
    if(queue->fim == NULL && queue->inicio == NULL) {
        queue->inicio = no; // tanto o inicio como o fim recebem o nó
    } else
        queue->fim->prox = no; // Não entendi muito bem essa parte!

    // fila não vazia 
    queue->fim = no; // Só o fim recebe o nó

    return 1;
}

int remove_queue(Queue *queue) {
    if(queue == NULL)
        return 0;
    
    if(queue->inicio == NULL && queue->fim == NULL) // fila vazia
        return 0;
    
    No *aux = queue->inicio; 
    queue->inicio = queue->inicio->prox; // inicio aponta para seu próximo elemento

    if(queue->inicio == NULL) // A fila ficou vazia 
        queue->fim = NULL; // Inicio e fim apontam para nulo
    
    free(aux);

    return 1;
}

int consult_queue(Queue *queue, int *valor) {
    if(queue == NULL)
        return 0;
    
    if(queue->inicio == NULL && queue->fim == NULL)
        return 0;

    *valor = queue->inicio->v;

    return 1;
}

int size_queue(Queue *queue) {
    if(queue == NULL) 
        return 0;
    
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