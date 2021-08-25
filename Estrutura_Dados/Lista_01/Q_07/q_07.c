#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Digite um número: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        if(num%i == 0) {
            count++;
        }
    }

    printf("%d", count);

    if(count == 2) {
        printf("[%d] é primo!\n", num);
    }else{
        printf("[%d] não é primo!\n", num);
    }

    return 0;
}