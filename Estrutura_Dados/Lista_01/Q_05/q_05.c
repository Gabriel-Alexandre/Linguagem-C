#include <stdio.h>

int main() {
    int start, end, cont;

    printf("Start: ");
    scanf("%d", &start);
    printf("End: ");
    scanf("%d", &end);

    // FOR:

    for(int i = start; i < end+1; i++) {
        printf("%d\n", i);
    }

    // WHILE:

    // cont = start;

    // while(cont < end+1) {
    //     printf("%d\n", cont);
    //     cont++;
    // }

    // DO WHILE:

    // cont = start;

    // do {
    //     printf("%d\n", cont);
    //     cont++; 
    // }while(cont < end+1);

    return 0;
}