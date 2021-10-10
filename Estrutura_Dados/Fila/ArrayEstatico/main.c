#include <stdio.h>
#include "arrayEstatico.h"

int main() {

    Queue *queue;
    int aux;

    queue = create_queue();

    printf("Inserindo 4 elementos:\n");

    for(int i = 0; i < 4; i++) {
        insert_queue(queue, i);
        consult_queue(queue, &aux);
        printf("Inicio: %d\n", aux);
        printf("Tamanho: %d\n", size_queue(queue));
    }

    printf("Removendo 4 elementos:\n");

    for(int i = 0; i < 4; i++) {
        remove_queue(queue);
        consult_queue(queue, &aux);
        printf("Inicio: %d\n", aux);
        printf("Tamanho: %d\n", size_queue(queue));
    }

    aux = isEmpty_queue(queue);
    if(aux) {
        printf("A fila está vazia\n");
    }else {
        printf("A fila não está vazia\n");
    }

    insert_queue(queue, 1);
    consult_queue(queue, &aux);
    printf("Inicio: %d\n", aux);
    printf("Tamanho: %d\n", size_queue(queue));

    aux = isEmpty_queue(queue);
    if(aux) {
        printf("A fila está vazia\n");
    }else {
        printf("A fila não está vazia\n");
    }

    printf("Enxendo a fila\n");
    for(int i = 0; i < 49; i++) {
        insert_queue(queue, i);
    }

    aux =isMax_queue(queue);

    if(aux) {
        printf("A fila está cheia\n");
    }else {
        printf("A fila não está cheia\n");
    }

    remove_queue(queue);

    aux =isMax_queue(queue);

    if(aux) {
        printf("A fila está cheia\n");
    }else {
        printf("A fila não está cheia\n");
    }

    return 0;
}