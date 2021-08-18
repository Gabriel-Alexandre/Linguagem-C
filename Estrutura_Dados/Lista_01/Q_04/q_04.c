#include <stdio.h>
#include <math.h>

// codigo para compilar: gcc q_04.c -lm (Indicando que estou incluindo uma biblioteca)

float delta(float a, float b, float c) {
    return (b*b) - (4*a*c);
}

void raiz(float delta, float a, float b, float *x, float *y) {
    *x = (-b + sqrt(delta)) / (2 * a);
    *y = (-b - sqrt(delta)) / (2 * a);
}

int main() {
    float var[3];
    float d, x, y;

    // 0 = A
    // 1 = B
    // 2 = C

    for(int i = 0; i < 3; i++) {
        printf("[%d]: ", i);
        scanf("%f", &var[i]);
    }

    d = delta(var[0], var[1], var[2]);
    raiz(d, var[0], var[1], &x, &y);

    printf("X = %.2f\n", x);
    printf("Y = %.2f\n", y);

    return 0;
}