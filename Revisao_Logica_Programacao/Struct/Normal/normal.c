#include <stdio.h>
#include <string.h>

typedef struct {
    int idade;
    char nome[20];
}cadastro_t;

// struct cadastro
//   {
//     int idade;
//     char nome[20];
// };

int main() {
    cadastro_t pessoa;
    // struct cadastro pessoa;

    printf("Nome: ");
    fgets(pessoa.nome, 20, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = 0;
    // Remover o \n lido pelo fgets()
    printf("Idade: ");
    scanf("%d", &pessoa.idade);
    printf("\n");

    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);

    return 0;
}