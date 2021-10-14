#include <stdio.h>
#include "arrayDinamico.h"

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

    printf("Ultrapassando dimenssão padrão de 20 elementos e inserindo 25 elementos...\n");
    for(int i = 0; i < 24; i++) {
        insert_stack(stack, i);
    }

    printf("Testando se realocação funcionou...\n");
    printf("Tamanho: %d\n", size_stack(stack));

    clear_stack(stack);

    return 0;
}