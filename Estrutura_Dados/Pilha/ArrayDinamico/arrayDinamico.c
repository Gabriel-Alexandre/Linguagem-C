#ifndef _ARRAYDINAMICO_C_
#define _ARRAYDINAMICO_C_
#include <stdio.h>
#include <stdlib.h>
#include "arrayDinamico.h"
#define TAM_SIZE 20

struct stack {
    int quant;
    int dim;
    int *stack;
};

// Padrão de retorno:

// return -1: Erro de criação da pilha
// return 0: Erro de execução da função
// return 1: Sucesso na execução da função

Stack *create_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if(stack != NULL) {
        stack->stack = (int *) malloc(TAM_SIZE*sizeof(int));
        if(stack->stack != NULL) {
            stack->quant = 0;
            stack->dim = TAM_SIZE;
        }else 
            return NULL;

    }

    return stack;
}

int insert_stack(Stack *stack, int valor) {
    if(stack == NULL)
        return -1;
    if(stack->quant == stack->dim) {
        stack->stack = (int *) realloc(stack->stack, 2*stack->dim*sizeof(int));
        if(stack->stack != NULL) {
            stack->dim = stack->dim * 2;
        }else
            return -1;
    }

    stack->stack[stack->quant] = valor;
    stack->quant++;
    return 1;
}

int remove_stack(Stack *stack) {
    if(stack == NULL)
        return -1;
    if(isEmpty_stack(stack))
        return 0;

    stack->quant--;
    return 1;
}

int consult_stack(Stack *stack, int *valor) {
    if(stack == NULL)
        return -1;
    
    if(!isEmpty_stack(stack)) {
        *valor = stack->stack[stack->quant-1];
        return 1;
    } else
        return 0;
}

int size_stack(Stack *stack) {
    if(stack == NULL) 
        return -1;

    return stack->quant;
}

int isEmpty_stack(Stack *stack) {
    if(stack == NULL)
        return -1;

    return (stack->quant == 0);
}

void clear_stack(Stack *stack) {
    free(stack->stack);
    free(stack);
}

#endif