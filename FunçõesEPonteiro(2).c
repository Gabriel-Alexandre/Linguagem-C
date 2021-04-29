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

    /*(&x1 e &x2) -> Significa que esses par�metros v�o receber o valor que est� guardado no espa�o de mem�ria reservado para o ponteiro
    criado no par�metro da fun��o "ResolveEquacao2Grau". (Isso � a indire��o -> O ponteiro criado na fun�ao "ResolveEquacao2Grau" guarda
                                                             endere�o atribuido a ele na fun��o "main" e retorna na fun��o "main" o valor
                                                             que foi atribuido a ele na fun��o "ResolveEquacao2Grau").
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
