#include <stdio.h>

int main (void)
{
    int N[20];
    int lerValores;
    int i, j;

    for(i = 0; i < 20; i++)
    {
        scanf("%d", &lerValores);

        N[i] = lerValores;
    }

    for(i = 0, j = 19; i < 20, j < 20; i++, j--)
    {
        if (i <= 19 && j >= 0)
            printf("N[%d] = %d\n", i, N[j]);
        else
            break;
    }

    return 0;
}
