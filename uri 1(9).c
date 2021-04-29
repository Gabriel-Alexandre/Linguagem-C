#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[51];
    float preco[51];
    int quant;
} tProduto;

//tProduto produto[produtosDisponiveis];
//tProduto quantidade[quantidadeDesejada];

tProduto produto[51];
tProduto quantidade[51];

void LerProdutosDisponiveis(int tamanho)
{
    int i, g;

    for(i = 0; i < tamanho; i++)
    {
        fgets(produto[i].nome, 51, stdin);
        scanf("%f", &produto[i].preco);
    }

    printf("1\n");
}

void LerQuantidadeProdutos(int tamanho)
{
    int i;

    printf("2\n");

    for(i = 0; i < tamanho; i++)
    {
        fgets(quantidade[i].nome, 51, stdin);
        scanf("%d", &quantidade[i].quant);
        printf("2\n");
    }
    printf("2\n");
}

int main (void)
{
    int teste;
    int i , j, NumPreco = 0;
    float soma = 0;
    char *p;

    int auxQuantidadeQuant[51];
    float auxProdutoPreco[51];
    char auxQuantidadeNome[51];
    char auxProdutoNome[51];

    scanf("%d", &teste);

    while(teste--)
    {
        int produtosDisponiveis;
        int quantidadeDesejada;

        scanf("%d", &produtosDisponiveis);
        LerProdutosDisponiveis(produtosDisponiveis);

        scanf("%d", &quantidadeDesejada); //O erro está aqui
        printf("%d\n", quantidadeDesejada);
        LerQuantidadeProdutos(quantidadeDesejada);

        strcpy(produto[i].nome, auxProdutoNome);
        strcpy(produto[i].preco, auxProdutoPreco);
        strcpy(quantidade[i].nome, auxQuantidadeNome);
        strcpy(quantidade[i].quant, auxQuantidadeQuant);

        for(i = 0; i < quantidadeDesejada; i++)
        {
            if(strcmp(auxProdutoNome, auxQuantidadeNome[i]))
            {
                *p = strstr(auxProdutoNome, auxQuantidadeNome[i]);

                for(j = 0; auxProdutoNome[j] != *p; j++)
                {
                    NumPreco++;
                }

                soma =  soma + (auxProdutoPreco[NumPreco] * auxQuantidadeQuant[i]);
            }
            else
                soma = soma + 0;
        }

        printf("R$ %.2f", soma);

        }

    return 0;
}
