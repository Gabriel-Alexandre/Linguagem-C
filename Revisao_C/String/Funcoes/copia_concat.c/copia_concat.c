#include <stdio.h>
#include <string.h>

int main() {
    const char origem[] = {"Gabriel"};
    char concatenado[] = {"Alexandre "};
    char destino[20];

    strcpy(destino, origem);
    // Nesse caso: origem == origem e destino == destino
    // Copia string "origem" em string "destino".
    // Retorna o endereço do primeiro elemento. (Pode ser importante em outras situações).

    strcat(concatenado, destino);
    // Nesse caso: origem == destino e destino == concatenado
    // Acrescenta os caracteres de uma string origem em uma string de destino.
    // Retorna o endereço do primeiro elemento da string de destino.

    printf("%s\n", concatenado);

    return 0;
}