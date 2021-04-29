#include <stdio.h>

int main (void)
{
    int X;
    int i;

    X = -1;

    while (X != 0){
        scanf("%d", &X);
            for (i = 1; (i < X); i = i + 1)
            {
                if (X == 0)
                    return 1;

                printf("%d ", i);
            }

        if (X == 0)
            return 1;

        printf("%d\n", i);
    }

    return 0;
}
