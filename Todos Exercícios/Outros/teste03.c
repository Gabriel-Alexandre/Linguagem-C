#include <stdio.h>
#include <string.h>

typedef struct
{
    char produto[51];
    float preco;
}tProduto;

int main (void)
{
    tProduto nomeProduto1[51];
    int teste;
    int i = 0, j, k;
    char aux[51];

    scanf("%d", &teste);

    while(teste--)
    {
        for(i = 0; i <= 2; i++)
        {
           fgets(nomeProduto1[i].produto, 51, stdin);
        }
    }

    //nomeProduto1[0].preco = 12;
    //aux = nomeProduto1[0].preco * nomeProduto1[1].preco;

    printf("%s\n", nomeProduto1[0].produto);
    printf("%s\n", nomeProduto1[1].produto);
    printf("%s\n", nomeProduto1[2].produto);
    //printf("%f\n", aux);

    return 0;
}

// -> Dica para consefuir fazer a quest�o:

//-> Fazer uma fun��o que guadar elementos em uma array e printa na tela
//-> Evoluir essa fun��o para guardar mais elementos e printar na tela
//-> Fazer uma fun��o que usa os valores que est�o guardados
//-> Fazer uma fun��o que faz uma opera��o com os valores que est�o guardados
//-> Fazer quest�o do uri
