#include <stdio.h>
#include <string.h>

int main() {
    char nome[30];
    int tamanho, n;

    printf("Numero: ");
    scanf("%d", &n);
    // Deixar o caracter "/n" armazenado no buffer
    getchar();
    // Remove o caracter "/n" armazenado no buffer

    printf("Digite um nome: ");
    fgets(nome, 30, stdin);
    // Lê strings

    tamanho = strlen(nome) - 1;
    // Calcula o tamanho da string


    printf("Tamanho: %d\n", tamanho);

    return 0;
}