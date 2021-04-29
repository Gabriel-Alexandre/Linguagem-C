#include <stdio.h>
#include <string.h>

int main(void)
{
    int teste;
    int contador = 1;

    scanf("%d", &teste);

    while(teste--)
    {
        char Sheldon[8];
        char Raj[8];

        scanf("%s", Sheldon);
        scanf("%s", Raj);

        if(!strcmp(Sheldon, Raj))
            printf("Caso #%d: De novo!\n", contador);

        else if((!(strcmp(Sheldon, "pedra")) && ((!strcmp(Raj, "lagarto")) || (!strcmp(Raj, "tesoura")))) ||
            ((!strcmp(Sheldon, "papel")) && ((!strcmp(Raj, "pedra")) || (!strcmp(Raj, "Spock" )))) ||
            ((!strcmp(Sheldon, "tesoura")) && ((!strcmp(Raj, "papel")) || (!strcmp(Raj, "lagarto")))) ||
            ((!strcmp(Sheldon, "lagarto")) && ((!strcmp(Raj, "papel")) || (!strcmp(Raj, "Spock")))) ||
            ((!strcmp(Sheldon, "Spock")) && ((!strcmp(Raj, "tesoura")) || (!strcmp(Raj, "pedra")))))
        {
            printf("Caso #%d: Bazinga!\n", contador);
        }else if(((!strcmp(Raj, "pedra")) && ((!strcmp(Sheldon, "lagarto")) || (!strcmp(Sheldon, "tesoura")))) ||
            ((!strcmp(Raj, "papel")) && ((!strcmp(Sheldon, "pedra")) || (!strcmp(Sheldon, "Spock")))) ||
            ((!strcmp(Raj, "tesoura")) && ((!strcmp(Sheldon, "papel")) || (!strcmp(Sheldon, "lagarto")))) ||
            ((!strcmp(Raj, "lagarto")) && ((!strcmp(Sheldon, "papel")) || (!strcmp(Sheldon, "Spock")))) ||
            ((!strcmp(Raj, "Spock")) && ((!strcmp(Sheldon, "tesoura")) || (!strcmp(Sheldon, "pedra")))))
        {
            printf("Caso #%d: Raj trapaceou!\n", contador);}

        contador++;
    }

    return 0;
}
