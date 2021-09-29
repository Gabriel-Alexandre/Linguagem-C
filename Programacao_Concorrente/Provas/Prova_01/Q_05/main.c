#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <time.h>
#define QTD_THREADS 12

double var_global;

void *func_thread(void *param) {
   long id = (long) param;
   time_t t;
   int aux;

    srand((unsigned)time(&t));

    // Verificar se o parâmetro recebido é um multiplo de 3 e
    // incrementa ou decrementa na variável global.
   if(id % 3 == 0) {
       aux = 1 + rand()%3;
        sleep(aux);

        for(int i = 0; i < 100; i++) {
            var_global++;
        }
   }else {
        sleep(1);

        for(int i = 0; i < 33; i++) {
            var_global--;
        }
   }

   printf("[ID]: %ld, [var_global]: %.2lf\n", id, var_global);
}

int main(void) {
    int fork_return;
    int pid_exit_value;
    pthread_t threads[QTD_THREADS];
    time_t t;
    int aux;

    srand((unsigned)time(&t));

    fork_return = fork();

    if(fork_return > 0) {
        // Processo original

        // Espera o processo clonado finalizar
        waitpid(fork_return, &pid_exit_value, 0);

        // Cria 12 threads
        for(long i = 0; i < QTD_THREADS; i++) {
            pthread_create(&threads[i], NULL, func_thread, (void *)i);
        }

        // Espera as 12 threads finalizarem
        for(long i = 0; i < QTD_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        printf("Valor aleatório gerado: %d\n", WEXITSTATUS(pid_exit_value));
        printf("[var_global]: %.2lf\n", var_global);
    }else {
        // Processo clonado

        // gera um valor aleatório e retorna o valor no fim do processo
        aux = 20 + rand()%60;
        exit(aux);
    }

    return 0;
}


/* Concorrência: 

    * Conjunto de tarefas sendo executadas de forma intercalada em um mesmo intervalo de tempo. 
    É uma forma de lidar com muitas coisas ao mesmo tempo e está ligado a forma de se estruturar tarefas.

*/

/* Elementos do sistema operacional que atuam durante a execução do programa:

    * Processo: É o programa em execução e o ambiente onde o programa vai ser executado. 
    Contém informações sobre a execução do programa e sobre os recursos que o programa pode utilizar como 
    espaço de endereçamento, uso do processador, área em disco, etc.

    * Thread: É uma "Linha" de execução dentro de um processo, no qual cada thread tem o seu próprio 
    estado de processador e a sua própria pilha. Além disso, todas as threads dentro de um mesmo processo 
    ocupam a mesma região de memória, o que facilita a troca de informações.

    * Escalonador: É o responsável por decidir a ordem de execução dos processos levando em conta critérios 
    como tempo de execução, tempo de espera, tempo de resposta, eficiência, justiça, etc.

    >> No código acima existe dois processos, no qual o processo original espera um valor de retorno do processo clonado,
    e no processo original são criadas 12 threads no qual cada uma incrementa 100 unidades ou decrementa 33 unidades da
    variável global (Região de memória compartilhada) e são justamente essas threads que tornam o programa concorrente, 
    pois uma thread não espera outra thread finalizar para está pronta para execução, o que acontece é: A partir do 
    momento que as threads são criadas, elas passam a competir entre si pelo acesso ao escalonador.
*/