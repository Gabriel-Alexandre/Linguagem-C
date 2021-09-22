#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Melhor explicação no código de wait X waitpid

int main(void) {
    pid_t fork_return;
    int valor_usuario;
    int retorno_filho = 0;

    printf("ORIGINAL: Processo original, PID: %d\n", getpid());

    fork_return = fork();

    if (fork_return >= 0) {
        //sucesso no fork
        if (fork_return == 0) {
            //processo clonado
            printf("CLONADO:\n");
            printf("CLONADO: PID %d\n", getpid());
            printf("CLONADO: PID do processo pai %d\n", getppid());
            printf("CLONADO: digite um valor inteiro (0 a 255): ");
            scanf("%d", &valor_usuario);
            printf("CLONADO: dormindo 5s antes de sair...\n");
            sleep(5);
            exit(valor_usuario);
        }
        else {
            //processo original
            printf("ORIGINAL:\n");
            printf("ORIGINAL: PID %d\n", getpid());
            printf("ORIGINAL: aguardando processo clonado sair...\n");
            wait(&retorno_filho);
            printf("ORIGINAL: processo original recebeu do clonado: %d\n", WEXITSTATUS(retorno_filho));
            sleep(5);
            printf("ORIGINAL: finalizando...\n");
            exit(0);
        }
    }
    else {
        //falha no fork
        printf("Erro ao invocar fork()!\n");
        exit(-1);
    }

    return 0;
}