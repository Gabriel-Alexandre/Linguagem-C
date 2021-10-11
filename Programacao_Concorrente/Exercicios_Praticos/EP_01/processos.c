#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#define TAM_PROCESSOS 6

int main() {

  char stringR[10];
  int somaT = 0;
  int pid_exit_values[TAM_PROCESSOS];

  printf("Digite a string desejada: ");
  fgets(stringR, 10, stdin);
  stringR[strlen(stringR)-1] = '\0';

  int pid_pai = getpid();

  // Cria 6 processos a partir do processo pai
  for (int i = 0; i < TAM_PROCESSOS; i++){
    if (getpid() == pid_pai){
      int fork_return = fork();
      
      // Procura as strings a partir do processo filho
      if(fork_return == 0) {
        int soma = 0;

        char j = i + 48;

        char aux[6];
        aux[0] = j;

        char linha[10];

        strcat(aux, ".txt");

        FILE *arq;
        arq = fopen(aux, "rt");

        while(fgets(linha, 10, arq)) {
            linha[strlen(linha)-1] = '\0';
            
            if(!strcmp(linha, stringR)) {
                soma++;
            }
        }

        fclose(arq);

        exit(soma);
      }
    }
  }

  // Espera os processos filhos finalizarem
  for(int i = 0; i < TAM_PROCESSOS; i++) {
    wait(&pid_exit_values[i]);
  }

  // Soma a partir dos valores de retorno
  for(int i = 0; i < TAM_PROCESSOS; i++) {
    somaT += WEXITSTATUS(pid_exit_values[i]);
  }

  printf("Soma das ocorrencias de [%s] é: %d\n", stringR, somaT);

  return 0;
}