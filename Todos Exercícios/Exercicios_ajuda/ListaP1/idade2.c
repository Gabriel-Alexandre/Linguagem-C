#include <stdio.h>

int main() {
    int pedro, joana, ismael;

    printf("Insira a idade de Pedro: ");
    scanf("%d", &pedro);

    printf("Insira a idade de Joana: ");
    scanf("%d", &joana);

    printf("Insira a idade de Ismael: ");
    scanf("%d", &ismael);

    if(pedro > joana && pedro > ismael)
        printf("Pedro é mais velho!\n");
    else if(joana > pedro && joana > ismael)
        printf("Joana é mais velha!\n");
    else
        printf("Ismael é mais velho!\n");

    return 0;
}