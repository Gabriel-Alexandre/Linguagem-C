#include <stdio.h>

int main (void)
{
    int N[10];
    int i, v;

    scanf("%d", &v);

    for(i = 0; i < 10; i++)
    {
        printf("N[%d] = %d\n", i, v);

        v *= 2;
    }

    return 0;
}
