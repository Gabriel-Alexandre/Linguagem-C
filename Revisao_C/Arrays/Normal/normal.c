#include <stdio.h>
#define NUMERO 5

int main() {
    // char array[5];

    // array[0] = 'a';
    // array[1] = 'b';
    // array[2] = 'c';

    int array[NUMERO] = {1, 2, 3};

    for(int i = 0; i < NUMERO; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

// O que falta revisar:

/*
1- Strings.
2- Relação entre funções e arrays.
*/

// Observações:

/*
-> Para se aprofundar mais nos assuntos, consultar os slides de documentação.
-> Ir aprendendo os novos assuntos necessários conforme for surgindo a necessidade.
-> Durante a revisão, foco em revisar aquilo que eu já sei, principalmente os tópicos mais obscuros.
*/