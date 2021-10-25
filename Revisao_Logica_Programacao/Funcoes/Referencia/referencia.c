#include <stdio.h>

void funcoValor(int numero) {

    numero = numero + 10;
}

void funcaoReferencia(int *numero) {

    *numero = *numero + 10;
    // Como estou lidando com o valor preciso usar o "*".
}

int main() {
    // int n = 12;
    // int resultado;

    // resultado = funcoValor(n);
    // A variável "n" continua sendo 12.

    int n = 12;

    // funcoValor(n);


    // funcaoReferencia(&n);
    // Como eu desejo uma passagem por referência preciso passar o endereço de memoria.


    printf("%d\n", n);

    /*
      Passagem de parâmetro por Valor X Referência:

      Valor: Eu passo um copia do valor do parametro. (Dessa maneira, tudo que acontece na função não altera o parâmetro 
      passado).

      -> Na linguagem C só existe passagem por valor. 
      -> Porém há uma maneira de simular a passagem por referência, que é passando o endereço de memoria e recebendo um
      ponteiro (mais ou menos o que acontece com os arrays), dessa maneira o que acontecer com o parametro passado, acontece
      com o original.

      Referência: Eu passo o parâmetro passado. (Dessa maneira, tudo que acontece na função altera o parâmetro 
      passado).
    */

    return 0;
}