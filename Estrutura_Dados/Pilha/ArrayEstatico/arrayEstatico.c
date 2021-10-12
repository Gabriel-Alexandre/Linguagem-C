#ifndef _ARRAYESTATICO_C_
#define _ARRAYESTATICO_C_
#include <stdio.h>
#include <stdlib.h>
#include "arrayEstatico.h"
#define MAX_SIZE 50

struct stack {
    int quant;
    int stack[MAX_SIZE];
};

// Padrão de retorno:
// -> Comecei a adotar esse padrão a partir da implementção das pilhas
// -> Continuar adotando esse padrão para implementção dos TADs

// return -1: Erro de criação da pilha
// return 0: Erro de execução da função
// return 1: Sucesso na execução da função

Stack *create_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if(stack != NULL)
        stack->quant = 0;

    return stack;
}

int insert_stack(Stack *stack, int valor) {
    if(stack == NULL)
        return -1;
    if(isMax_stack(stack))
        return 0;

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

int isMax_stack(Stack *stack) {
    if(stack == NULL)
        return -1;
    
    return (stack->quant == MAX_SIZE);
}

void clear_stack(Stack *stack) {
    free(stack);
}

#endif