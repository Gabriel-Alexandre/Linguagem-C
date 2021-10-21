#ifndef _PILHA_H_
#define _PILHA_H_

typedef struct stack Stack;
typedef struct no No;

Stack *create_stack();
int insert_stack(Stack *stack, int valor);
int remove_stack(Stack *stack);
int consult_stack(Stack *stack, char *valor);
int size_stack(Stack *stack);
int isEmpty_stack(Stack *stack);
void clear_stack(Stack *stack);

#endif