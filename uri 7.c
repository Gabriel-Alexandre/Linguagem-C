#include <stdio.h>

int main (void)
{
    int N;
    int M;

    scanf("%d", &N);

    printf("1 x %d = %d\n", N, N);
    printf("2 x %d = %d\n", N, M = 2 * N);
    printf("3 x %d = %d\n", N, M = 3 * N);
    printf("4 x %d = %d\n", N, M = 4 * N);
    printf("5 x %d = %d\n", N, M = 5 * N);
    printf("6 x %d = %d\n", N, M = 6 * N);
    printf("7 x %d = %d\n", N, M = 7 * N);
    printf("8 x %d = %d\n", N, M = 8 * N);
    printf("9 x %d = %d\n", N, M = 9 * N);
    printf("10 x %d = %d\n", N, M = 10 * N);

    return 0;
}
