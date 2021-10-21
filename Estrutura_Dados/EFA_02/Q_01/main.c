#include <stdio.h>
#include <string.h>
#include "pilha.h"

int verificar_sentenca(char sentenca[]) {
    Stack *stack;
    char caracter;
    int aux, quant;
    int c1 = 0; int c2 = 0;

    quant = strlen(sentenca);

    if(quant == 0) {
        return 0;
    }

    stack = create_stack();

    for(int i = 0; i < quant; i++) {
        
        // Empilhando caracteres de abertura
        if(sentenca[i] == '{' || sentenca[i] == '(' || sentenca[i] == '[') {
            insert_stack(stack, sentenca[i]);
            c1++;
        }
        
        // Desempilhando caracteres de abertura apartir do topo

        // Se o caracter de fechamento não for o correspondente a caracter de abertura 
        // do topo, não desempilhar.

        if(sentenca[i] == '}' || sentenca[i] == ')' || sentenca[i] == ']') {
            consult_stack(stack, &caracter);

            if(caracter == '{')
                caracter = '}';
            else if(caracter == '(')
                caracter = ')';
            else if(caracter == '[')
                caracter = ']';

            if(caracter == sentenca[i]) {
                remove_stack(stack);
                c2++;
            }else {
                return 0;
            }
        }
    }

    // Verificar se a sentença está correta

    // A sentença estará correta se a pilha estiver vazia e se o número de
    // caracteres de fechamento for igual a número de caracteres de abertura.
    
    if(isEmpty_stack(stack) && c1 == c2)
        aux = 1;
    else
        aux = 0;

    clear_stack(stack);

    return aux;
}

int main() {
    // Casos de teste
    char *testes[] = {"[{()()}{}]", "{[([{}])]}", "{[(}])", "{[)()(]}",
                    "[[{()}}]", "{{{{)))]", "{}()[][[{}]]"};
    
    // Verificando sentenças
    for(int i = 0; i < 7; i++) {
        if(verificar_sentenca(testes[i])) {
            printf("%s - É correta\n", testes[i]);
        } else {
            printf("%s - Não é correta\n", testes[i]);
        }
    }

    return 0;
}
