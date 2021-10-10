#ifndef _ARRAYESTATICO_C_
#define _ARRAYESTATICO_C_
#include <stdio.h>
#include <stdlib.h>
#include "arrayEstatico.h"
#define MAX_SIZE 50

struct queue {
    int inicio, fim, quantidade;
    int valor[MAX_SIZE];
};

// *Inserção no fim. (fim -> Próxima posição vazia no fim)
// *Remoção no inicio.

Queue *create_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if(queue != NULL) {
        queue->inicio = 0;
        queue->fim = 0;
        queue->quantidade = 0;
    }

    return queue;
}

int insert_queue(Queue *queue, int valor) {
    if(queue != NULL) {

        if(isMax_queue(queue)) {
            return 0;
        }

        queue->valor[queue->fim] = valor;
        queue->fim = (queue->fim + 1) % MAX_SIZE;
        // Essa operação garante a circularidade da fila, ou seja, quando a fila estiver
        // cheia, o indice fim apontara para a primeira posição.
        queue->quantidade++;

        return 1;
    }

    return 0;
}

int remove_queue(Queue *queue) {
    if(queue != NULL) {
        if(isEmpty_queue(queue)) {
            return 0;
        }

        queue->inicio = (queue->inicio + 1) % MAX_SIZE;
        // Essa operação garante a circularidade da fila, ou seja, quando a fila estiver
        // cheia, o indice fim apontara para a primeira posição.
        queue->quantidade--;
    }

    return 0;
}

int consult_queue(Queue *queue, int *valor) {
    if(queue != NULL) {
        if(isEmpty_queue(queue)) {
            return 0;
        }

        *valor = queue->valor[queue->inicio];

        return 1;
    }

    return 0;
}

int size_queue(Queue *queue) {
    if(queue != NULL) {
        return queue->quantidade;
    }

    return -1;
}

int isEmpty_queue(Queue *queue) {
    if(queue != NULL) {
        if(queue->quantidade == 0) {
            return 1;
        }else {
            return 0;
        }
    }
    
    return -1;
}

int isMax_queue(Queue *queue) {
    if(queue != NULL) {
        if(queue->quantidade == MAX_SIZE) {
            return 1;
        }else {
            return 0;
        }
    }

    return -1;
}

void clear_queue(Queue *queue) {
    free(queue);
}


#endif