#include <stdio.h>
#include <string.h>

int main() {
    char input[30], search;
    int count = 0;

    printf("Digite um palavra: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Busque por um caracter: ");
    scanf("%c", &search);

    for(int i = 0; i < 30; i++) {
        if(input[i] == search) {
            count++;
        }
    }

    printf("(%c) ocorreu %d vezes\n", search, count);

    return 0;
}