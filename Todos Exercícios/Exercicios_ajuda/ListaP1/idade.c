#include <stdio.h>

int main() {
    int pedro, joana;

    printf("Insira a idade de Pedro: ");
    scanf("%d", &pedro);

    printf("Insira a idade de Joana: ");
    scanf("%d", &joana);

    if(pedro > joana)
        printf("Pedro é mais velho!\n");
    else
        printf("Joana é mais velha!\n");

    return 0;
}