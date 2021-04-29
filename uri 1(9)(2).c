#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[51];
    float preco;
    int quant;
}tProduto;

int main (void)
{
    int teste;

    scanf("%d", &teste);

    while(teste--)
    {
        int produtosDisponiveis;
        int quantidadeDesejada;

        scanf("%d", &produtosDisponiveis);

        int i;
        tProduto produto[produtosDisponiveis];

        for(i = 0; i < produtosDisponiveis; i++)
        {
            scanf("%s", produto[i].nome);
            scanf("%f", &produto[i].preco);
        }

        scanf("%d", &quantidadeDesejada);

        int j;
        tProduto quantidade[quantidadeDesejada];

        for(j = 0; j < quantidadeDesejada; j++)
        {
            scanf("%s", quantidade[j].nome);
            scanf("%d", &quantidade[j].quant);
        }

        int k, l;
        float soma = 0;

        for(k = 0; k < quantidadeDesejada; k++)
        {
            for(l = 0; l < produtosDisponiveis; l++)
            {
                if(!strcmp(quantidade[k].nome, produto[l].nome))
                {
                    soma += (quantidade[k].quant * produto[l].preco);
                    break;
                }
            }
        }

        printf("R$ %.2f\n", soma);

    }

    return 0;
}
