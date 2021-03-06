#ifndef _ARRAYESTATICO_H_
#define _ARRAYESTATICO_H_

typedef struct stack Stack;

Stack *create_stack();
int insert_stack(Stack *stack, int valor);
int remove_stack(Stack *stack);
int consult_stack(Stack *stack, int *valor);
int size_stack(Stack *stack);
int isEmpty_stack(Stack *stack);
int isMax_stack(Stack *stack);
void clear_stack(Stack *stack);

#endif