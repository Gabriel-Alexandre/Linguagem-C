#include <stdio.h>

int main (void)
{
    int T;
    int R1, R2;
    int total;
    int contador = 0;

    scanf("%d", &T);

    while(contador < T)
    {
        scanf("%d %d", &R1, &R2);
        printf("%d\n", total = R1 + R2);

        contador = contador + 1;
    }

    return 0;
}
