#include <stdio.h>
#include "listaEncadeada.h"

int main() {

    Stack *stack;
    int aux;

    stack = create_stack();

    printf("Inserindo 4 elementos:\n");

    for(int i = 0; i < 4; i++) {
        insert_stack(stack, i);
        consult_stack(stack, &aux);
        printf("Topo: %d\n", aux);
        printf("Tamanho: %d\n", size_stack(stack));
    }

    printf("Removendo 4 elementos:\n");

    for(int i = 0; i < 4; i++) {
        remove_stack(stack);
        consult_stack(stack, &aux);
        printf("Topo: %d\n", aux);
        printf("Tamanho: %d\n", size_stack(stack));
    }

    aux = isEmpty_stack(stack);
    if(aux) {
        printf("A pilha está vazia\n");
    }else {
        printf("A pilha não está vazia\n");
    }

    insert_stack(stack, 0);
    consult_stack(stack, &aux);
    printf("Topo: %d\n", aux);
    printf("Tamanho: %d\n", size_stack(stack));

    aux = isEmpty_stack(stack);
    if(aux) {
        printf("A pilha está vazia\n");
    }else {
        printf("A pilha não está vazia\n");
    }

    clear_stack(stack);

    return 0;
}