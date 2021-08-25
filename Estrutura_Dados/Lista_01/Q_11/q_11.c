#include <stdio.h>

int main() {
    int num[] = {1, 2, 3, 16, 5, 6, -20, 8};
    int maior, menor;

    for(int i = 0; i < sizeof(num)/sizeof(num[0]); i++) {
        
        if(i == 0) {
            maior = num[i];
            menor = num[i];
        }else {
            maior = num[i] > maior ? num[i] : maior;
            menor = num[i] < menor ? num[i] : menor;
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}