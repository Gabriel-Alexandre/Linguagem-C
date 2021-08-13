#include <stdio.h>

int main() {
    int x;
    int *p;

    x = 3;
    p = &x;
    *p = 4;

    printf("%p\n", &x);

    return 0;
}