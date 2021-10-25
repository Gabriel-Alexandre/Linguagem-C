#include <stdio.h>
#include <math.h>

int ResolveEquacao2Grau(float a, float b, float c, float *x1, float *x2)
{
    float delta;

    if (a == 0)
        return -1;

    delta = (b * b) - (4 * a * c);

    if (delta < 0)
        return -2;

    *x1 = ((-b) + sqrt(delta)) / (2 * a);
    *x2 = ((-b) - sqrt(delta)) / (2 * a);

    return 0;
}

int main (void)
{
    float a, b, c, recebe, x1, x2;

    printf("Digite o coeficiente (A): ");
    scanf("%f", &a);
    printf("Digite o coeficiente (B): ");
    scanf("%f", &b);
    printf("Digite o coeficiente (c): ");
    scanf("%f", &c);

    /*(&x1 e &x2) -> Significa que esses parâmetros vão receber o valor que está guardado no espaço de memória reservado para o ponteiro
    criado no parâmetro da função "ResolveEquacao2Grau". (Isso é a indireção -> O ponteiro criado na funçao "ResolveEquacao2Grau" guarda
                                                             endereço atribuido a ele na função "main" e retorna na função "main" o valor
                                                             que foi atribuido a ele na função "ResolveEquacao2Grau").
     */
    recebe = ResolveEquacao2Grau(a, b, c, &x1, &x2);

    if (recebe == -1)
        printf("O valores digitados nao formam um equacao do 2 grau!");

    if (recebe == -2)
        printf("A equacao nao possui raizes reais!");

    if (recebe == 0)
    {
        printf("O valor de X1 eh: %.1f\n", x1);
        printf("O valor de X2 eh: %.1f\n", x2);
    }

    return 0;
}
