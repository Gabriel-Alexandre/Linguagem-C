#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[51];
    float preco;
    int quant;
} tProduto;
/*
void LerProdutosDisponiveis(const tProduto *produto, int tamanho)
{
    int i;

    for(i = 0; i <= tamanho; i++)
    {
        fgets(produto[i].nome, 51, stdin);
        scanf("%d", &produto[i].preco);
    }
}

void LerQuantidadeProdutos(const tProduto *quantidade, int tamanho)
{
    int i;

    for(i = 0; i <= tamanho; i++)
    {
        fgets(quantidade[i].nome, 51, stdin);
        scanf("%d", &quantidade[i].quant);
    }
}*/

int main (void)
{
    int teste;
    static float soma;
    int i;

    scanf("%d", &teste);

    while(teste--)
    {
        int produtosDisponiveis;
        int quantidadeDesejada;

        scanf("%d", &produtosDisponiveis);
        tProduto produto[produtosDisponiveis];
        //LerProdutosDisponiveis(&produto, produtosDisponiveis);

        int i;

        for(i = 0; i <= produtosDisponiveis; i++)
        {
            fgets(produto[i].nome, 51, stdin);
            scanf("%d", &produto[i].preco);
        }

        scanf("%d", &quantidadeDesejada);
        tProduto quantidade[quantidadeDesejada];
        //LerQuantidadeProdutos(&quantidade, quantidadeDesejada);

        int j;

        for(j = 0; j <= quantidadeDesejada; j++)
        {
            fgets(quantidade[j].nome, 51, stdin);
            scanf("%d", &quantidade[j].quant);
        }

        //Valor Final

        int k;

        /*for(k = 0; k <= produtosDisponiveis; k++)
        {
            if(strstr(produto.nome, quantidade[k].nome))
                soma =  soma + (produto[k].preco * quantidade[k].quant);
            else
                soma = soma + 0;
        }

        printf("R$ %.2f", soma);*/

        printf("%s %d", produto[i].nome, produto[i].preco);

        }

    return 0;
}
