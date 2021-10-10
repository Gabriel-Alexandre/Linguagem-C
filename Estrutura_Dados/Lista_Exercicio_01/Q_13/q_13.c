#include <stdio.h>
#include <string.h>

int main() {
    char input[30], search;
    int count = 0;
    char base[] = "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWYZX ";
    int baseCount[strlen(base)];

    for(int i = 0; i < strlen(base); i++) {
        baseCount[i] = 0;
    }

    printf("Digite um palavra: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < strlen(base); j++) {
            if(input[i] == base[j]) {
                baseCount[j]++;
            }
        }
    }

    for(int i = 0; i < strlen(base); i++) {
        if(baseCount[i] != 0) {
            printf("(%c) ocorreu %d vezes\n", base[i], baseCount[i]);
        }
    }

    return 0;
}