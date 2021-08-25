#include <stdio.h>

int main() {
    int start, end;
    int soma = 0;

    printf("Numero inicial: ");
    scanf("%d", &start);
    printf("Numero Final: ");
    scanf("%d", &end);

    for(int i = start; i <= end; i++) {
        soma += i;
    }

    printf("%d\n", soma);
    
    return 0;
}