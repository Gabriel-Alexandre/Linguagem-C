#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int pid_to_wait;
    int pid_exit_value;
    int wait_return_value;

    // waitpid ((PID Esperado), (Variável que vai receber o valor), (Opções de funcionamento))
    // wait ((Variável que vai receber o valor))

    // Lembrar: Essa variável recebida precisa ser formata para exibir o valor correto.
    
    // Difença: wait X waitpid

    // wait: Coloca o processo de chamada em espera, até que um de seus processos filhos sejam encerrados.
    // waitpid: Espera o processo clonado indicado na chamada da função encerrar. (Se recever -1, funcionara com wait).

    // Precisa ser um processo clonada. Se eu pegar um processo arbitrário não vai dar certo.

    //Obs:

    // getpid(): Retorna pid do processo em execução.
    // getppid(): Retorna pid do processo pai do processo em execução.

    pid_to_wait = fork();

    if (pid_to_wait > 0)
    {

        //processo original

        printf("[O] Aguardando termino do processo com PID %d\n",
               pid_to_wait);

        wait_return_value = waitpid(pid_to_wait, &pid_exit_value, 0);

        printf("[O] Valor de retorno do processo aguardado: %d\n",
               WEXITSTATUS(pid_exit_value));

        printf("[O] Valor de retorno do wait: %d\n", wait_return_value);
    }
    else
    {
        //processo clonado
        printf("[C] Vou dormir 20s...\n");
        sleep(20);
        exit(66);
    }

    return 0;
}