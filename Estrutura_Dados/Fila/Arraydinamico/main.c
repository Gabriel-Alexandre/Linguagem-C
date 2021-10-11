#include <stdio.h>
#include "arrayDinamico.h"

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

    printf("Ultrapassando dimenssão padrão de 20 para 25\n");
    for(int i = 0; i < 25; i++) {
        insert_queue(queue, i);
    }

    printf("Testando se realocação funcionou\n");
    printf("Tamanho: %d\n", size_queue(queue));

    clear_queue(queue);

    return 0;
}