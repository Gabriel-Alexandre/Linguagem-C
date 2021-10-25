#include <stdio.h>
#include <string.h>

int main() {

  typedef struct {
    char nome[30];
    int idade;
    float salario;
  } t_funcionario;

  t_funcionario funcionario;
  // t_funcionario *funcionario;

  printf("Nome: ");
  fgets(funcionario.nome, 30, stdin);
  funcionario.nome[strcspn(funcionario.nome, "\n")] = 0;

  // printf("Nome: ");
  // fgets(funcionario->nome, 30, stdin);
  // funcionario->nome[strcspn(funcionario->nome, "\n")] = 0;

  printf("Idade: ");
  scanf("%d", &funcionario.idade);

  printf("Salario: ");
  scanf("%f", &funcionario.salario);

  // printf("Idade: ");
  // scanf("%d", &funcionario->idade);

  // printf("Salario: ");
  // scanf("%f", &funcionario->salario);

  printf("Nome: %s\n", funcionario.nome);
  printf("Idade: %d\n", funcionario.idade);
  printf("Salario: %.2f\n", funcionario.salario);

  // printf("Nome: %s\n", funcionario->nome);
  // printf("Idade: %d\n", funcionario->dade);
  // printf("Salario: %.2f\n", funcionario->salario);

  return 0;
}