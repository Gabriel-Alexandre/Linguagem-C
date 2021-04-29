#include <stdio.h>
#include <string.h>

int main (void)
{
    char S[101];
    char D[101];

    while(scanf("%s %s", D, S)!= EOF)
    {
        if(strstr(D, S))
            printf("Resistente\n");
        else
            printf("Nao resistente\n");
    }

     return 0;
}
