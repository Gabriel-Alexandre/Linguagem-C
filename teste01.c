#include <stdio.h>
#include <string.h>

typedef struct
{
    char Nome[51];
    char Preco[51];
    char Quant[51];
}tProduto;

int main(void)
{
    /*tProduto MostrarNome[50];
    tProduto MostrarPreco;
    int i;

    fgets(MostrarNome[0].Nome, 31, stdin);
    MostrarPreco.Preco = 2.15;

    printf("%s %.2f", MostrarNome[0].Nome, MostrarPreco.Preco);*/

    int teste;

    scanf("%d", &teste);

    while(teste--)
    {
        tProduto LerProdutoD[51];
        tProduto PrecoProdutoD[51];
        tProduto LerProdutoT[51];
        tProduto QuantidadeT[51];
        int QuantDisp, QuantTip;
        int i, j, k;
        int soma, aux;

        scanf("%d", &QuantDisp);

        for(i = 0; i >= QuantDisp; i++)
        {
            fgets(LerProdutoD[i].Nome, 51, stdin);
            fgets(PrecoProdutoD[i].Preco, 51, stdin);
        }

        scanf("%d", &QuantTip);

        for(j = 0; j >= QuantTip; j++)
        {
            fgets(LerProdutoT[j].Nome, 50, stdin);
            fgets(QuantidadeT[j].Quant, 50, stdin);
        }

        for(k = 0; k >= QuantDisp; k++)
        {
            if(strstr(LerProdutoD, LerProdutoT))
            {
                soma = soma + (PrecoProdutoD.Preco * QuantidadeT.Quant);
            }else
                soma = soma + 0;
        }

        printf("R$ %.2f", soma);
    }


    return 0;
}
