#include <stdio.h>

int main () {

    int a, contador;

    a = 0;

    // while(contador < a) {
    //     printf("%d\n", contador);
    //     contador++;
    // }

    do {
        printf("%d\n", contador);
        contador++;
    }while(contador < a);

    return 0;
}