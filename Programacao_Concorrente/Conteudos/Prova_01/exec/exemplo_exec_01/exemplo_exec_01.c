#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define QUANTIDADE_LISTA 5
#define TAM_STR 8
#define STR_TESTE "AAAAAAA"

int main(void)
{   
    // A família de funções exec são função que executão programas externos de diferentes formas:

    // execv((Caminho do executável), (Array de strings))
    // execv((Caminho do executável), (Array de strings), (variável ambiente))
    // execl((Caminho do executável), String, String, ..., (char *)NULL)

    // Lembrar: Eu preciso colar o NULL no final do array de strings.
    // Lembrar: As listas passadas precisam ser na forma de ponteiro.

    // Essa maneira como foi feito só serve para executar um único processo
    // porque quando a função exec é executada ele substitui o processo de exemplo_exec_01 para
    // mostra_params, o que faz o contexto do processo exemplo_exec_01 deixar de existir.

    // O ideal é que eu faça clones deste processo, e apartir desses clones executar o que foi desejado,
    // dessa maneira, vou poder executar diferentes processos sem perder o contexto do meu processo central.
    // (Esse procedimento pode ser visto em: exemplo_exec_02).

    int i;
    char *tmp[] = {"abc", "def", "xyz", NULL};
    char *lista[QUANTIDADE_LISTA + 1];

    for (i = 0; i < QUANTIDADE_LISTA; i++)
    {
        lista[i] = (char *)malloc(sizeof(char) * TAM_STR);
        strcpy(lista[i], STR_TESTE);
    }

    lista[i] = NULL;
  
    printf("[PEE] segunda execucao: \n");
    execv("../mostra_params/a.out", tmp);

    return 0;
}