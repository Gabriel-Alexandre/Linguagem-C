#include <stdio.h>

int main() {
    int op;
    float salario, salario1, op2, horasT, comissao, resultado, soma = 0;

    while(1) {
        printf("Calcular salário dos funcionários\n");

        printf("\n[1] assalariado\n");
        printf("[2] por hora\n");
        printf("[3] comissionado\n");
        printf("[4] assalariado/comissionado\n");
        printf("[0} sair\n");

        printf("Escolha o tipo de salário: ");
        scanf("%d", &op);

        if(op == 0)
            break;
        
        switch(op) {
            case 1:
                printf("Salário: ");
                scanf("%f", &salario);

                printf("\nSalário: %.2f\n", salario);
                break;
            case 2:
                printf("Salário: ");
                scanf("%f", &salario);
                printf("Horas trabalhadas: ");
                scanf("%f", &horasT);

                if(horasT > 40) {
                    resultado = ((salario/horasT) * 1.5) * (horasT - 40) + salario;
                } else {
                    resultado = salario;
                }

                printf("\nSalário: %.2f\n", resultado);
                break;
            case 3:
                printf("Comissão: ");
                scanf("%f", &comissao);

                while(1) {
                    printf("Vendas \n\n");

                    printf("Digite o valor da venda (ou '0' para sair): ");
                    scanf("%f", &op2);
                    
                    if(op2 == 0)
                        break;
                    
                    salario1 += op2 * comissao;
                }

                printf("\nSalário: %.2f\n", salario1);
                break;
            case 4:
                printf("Salário: ");
                scanf("%f", &salario);
                printf("Comissão: ");
                scanf("%f", &comissao);

                while(1) {
                    printf("Vendas \n\n");

                    printf("Digite o valor da venda (ou '0' para sair): ");
                    scanf("%f", &op2);
                    
                    if(op2 == 0)
                        break;
                    
                    soma += op2 * comissao;
                }

                printf("\nSalário: %.2f\n", salario + soma);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } 

    return 0;
}
