#include <stdio.h>

int main() {
    int array[3] = { 1, 2, 3 };
    int *p;

    p = &array[1]; // *p = 2
    p = p + 1; // *p = 3

    printf("%d\n", *p);

    return 0;
}