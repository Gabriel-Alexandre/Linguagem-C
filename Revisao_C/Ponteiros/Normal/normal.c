#include <stdio.h>

int main() {
    int x;
    int *p;
    int **q;

    // * -> Operador de indireção (Eu acesso o valor da variável)
    // ** -> Operador de indireção multipla  (Eu acesso o valor da variável)


    x = 3;
    p = &x;
    *p = 4;
    q = &p;

    printf("%d\n", **q);

    return 0;
}