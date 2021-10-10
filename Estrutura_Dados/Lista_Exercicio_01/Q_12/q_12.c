#include <stdio.h>
#include <string.h>

int main() {
    char input[20], aux;
    int tamanho;

    printf("Digite um palavra: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    tamanho = strlen(input);
    aux = input[tamanho-1];
    
    for(int i = tamanho - 1; i >= 0; i--) {
        input[i] = aux;
        printf("%s\n", input);
    }

    return 0;
}