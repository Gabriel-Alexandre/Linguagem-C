#include <stdio.h>

int main(void) {
    int a;
    int b;
    int resultado;

    a = 5;
    b = 2;

    // resultado = a + b;
    // resultado = a * b;
    // resultado = a / b;
    // resultado = a % b;

    scanf("%d", &a);
    scanf("%d", &b);

    resultado = a;

    printf("a=%d, b=%d, resultado=%d\n", a, b, resultado);

    return 0;
}
