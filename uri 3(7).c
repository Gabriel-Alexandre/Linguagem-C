#include <stdio.h>

int main (void)
{
    float A[100];
    float lerValores;
    int i;

    for(i = 0; i < 100; i++)
    {
        scanf("%f", &lerValores);

        A[i] = lerValores;

        if(A[i] <= 10)
            printf("A[%d] = %.1f\n", i, A[i]);
    }

    return 0;
}
