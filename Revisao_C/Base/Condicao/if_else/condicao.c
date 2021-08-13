#include <stdio.h>

int main() {
    int a, b, resultado;

    scanf("%d", &a);
    scanf("%d", &b);

    // if (!(a > b) || 1) {
    //     printf("a=%d e maior!\n", a);
    // }else {
    //     printf("b=%d e maior!\n", b);
    // }

    // if (!(a > b) && 1) {
    //     printf("a=%d e maior!\n", a);
    // }else {
    //     printf("b=%d e maior!\n", b);
    // }

    if (a > b) {
        printf("a=%d e maior!\n", a);
    }else if (a==b) {
        printf("a=%d e b=%d sao iguais!\n", a, b);
    }
    else {
        printf("b=%d e maior!\n", b);
    }

    return 0;
}