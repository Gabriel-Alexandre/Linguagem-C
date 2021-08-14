#include <stdio.h>

int main() {
    char nome[] = {"Gabriel"};
    // Strings normais
    char *nome_01[] = {"Gabriel"};
    // String constantes (Não podem ser alteradas).
    const char *nome_02[] = {"Gabriel"};
    // Essa é a maneira correta de declarar um string constante.

    nome[0] = 'g';
    *nome_01[0] = 'g';
    
    
    // Lembrar: Strings são arrays de caracteres que terminam com "/0" (Por isso o array inicia no 0 geralmente)

    printf("%c", *nome_01[0]);

    return 0;
}