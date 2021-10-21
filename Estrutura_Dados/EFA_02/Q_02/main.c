#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

int verificar_sentenca(char sentenca[]) {
    Stack *stack;
    Queue *queue;
    char caracterStack, caracterQueue;
    int aux, quant;

    quant = strlen(sentenca);

    if(quant == 0) {
        return 0;
    }

    stack = create_stack();
    queue = create_queue();

    // Inserindo elementos na fila e na pilha
    
    // Fila - Sentença na ordem padrão
    // Pilha - Sentença na ordem inversa

    for(int i = 0; i < quant; i++) {
        insert_queue(queue, sentenca[i]);
        insert_stack(stack, sentenca[i]);
    }

    // Se todos os caracteres inseridos na pilha e na fila forem
    // iguais, a sentença é palíndroma
    
    for(int i = 0; i < quant; i++) {
        consult_queue(queue, &caracterQueue);
        consult_stack(stack, &caracterStack);

        if(caracterQueue == caracterStack)
            aux = 1;
        else {
            aux = 0;
            break;
        }
    }

    clear_stack(stack);
    clear_queue(queue);

    return aux;
}

int main() {

    // Casos de teste
    char *testes[] = {"ANA", "JOAO", "ALBERTO", "AMOR A ROMA",
                    "LAVA ESSE AVAL", "GABRIEL", "ALEXANDRE"};
    
    // Verificando sentenças
    for(int i = 0; i < 7; i++) {
        if(verificar_sentenca(testes[i])) {
            printf("%s - É Palíndroma\n", testes[i]);
        } else {
            printf("%s - Não é Palíndroma\n", testes[i]);
        }
    }

    return 0;
}