#include <stdio.h>

int main (void)
{
    int X[10];
    int t, i, recebe;

    t = 10;

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &recebe);

        X[i] = recebe;

        if(recebe > 0)
            printf("X[%d] = %d\n", i, X[i]);
        else
            printf("X[%d] = %d\n", i, 1);
    }

    return 0;
}
