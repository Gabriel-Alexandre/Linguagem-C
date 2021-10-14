#ifndef _LISTAENCADEADA_C_
#define _LISTAENCADEADA_C_
#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// Nesse caso, o sentido de implementação é diferente do sentido real da fila.

struct stack {
    No *topo;
};

// Eu poderia criar um elemento "int quantidade", para manipular durante a inserção, dessa maneira 
// na função de tamanho, eu precisaria apenas retornar a quantidade. (Acredito que essa implementação
// seria mais eficiente, mas eu fiz da maneira mais difícil por fins didáticos). 

// Padrão de retorno:

// return -1: Erro de criação da pilha
// return 0: Erro de execução da função
// return 1: Sucesso na execução da função

struct no {
    No *prox;
    int v;
};

Stack *create_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if(stack != NULL) {
        // pilha vazia
        // topo aponta para nulo
        stack->topo = NULL;
    }

    return stack;
}

int insert_stack(Stack *stack, int valor) {
    if(stack == NULL)
        return -1;
    
    No *no = (No *) malloc(sizeof(No));

    if(no == NULL)
        return -1;
    
    no->v = valor;

    // pilha não vazia
    if(!isEmpty_stack(stack)) {
        no->prox = stack->topo;
    } else {
        // pilha vazia
        no->prox = NULL;
    }

    stack->topo = no;

    return 1;
}

int remove_stack(Stack *stack) {
    if(stack == NULL)
        return -1;
    
    if(isEmpty_stack(stack)) // pilha vazia
        return 0;
    
    No *aux = stack->topo; 
    stack->topo = stack->topo->prox; // topo aponta para seu próximo elemento
    
    free(aux);

    return 1;
}

int consult_stack(Stack *stack, int *valor) {
    if(stack == NULL)
        return -1;
    
    if(isEmpty_stack(stack)) // pilha vazia
        return 0;

    *valor = stack->topo->v;

    return 1;
}

int size_stack(Stack *stack) {
    if(stack == NULL) 
        return -1;
    
    No *aux = stack->topo;
    int cont = 0;

    // Conta até o atributo próximo de topo ser nulo
    while(aux != NULL) {
        cont++;
        aux = aux->prox;
    }

    return cont;
}

int isEmpty_stack(Stack *stack) {
    if(stack == NULL)
        return -1;
    if(stack->topo == NULL)
        return 1;
    
    return 0;
}

void clear_stack(Stack *stack) {
    if(stack != NULL) {
        No *aux;

        // libera até o atributo próximo de inicio ser nulo
        while(stack->topo != NULL) {
            aux = stack->topo;
            stack->topo = stack->topo->prox;
            free(aux);
        }
        
        free(stack);
    }
}

#endif