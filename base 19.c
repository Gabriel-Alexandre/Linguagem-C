#include <stdio.h>

int main (void)
{
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade <= 21){
        printf("Jovem");}
    else {
        if (idade <= 65){
            printf("Adulto");}
        else {
            printf("Idoso");}
         }

    return 0;
}
