#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define QTD_THREADS 5

long var_global;

// Toda funcao thread precisa ter esse cabeçalho
void *funcao_thread(void *param)
{
    long id = (long)param;
    printf("[#%d] Thread %d criada!\n", id, id);
    sleep(5);
    var_global++;
    printf("[#%d] var_global = %d\n", id, var_global);
    pthread_exit((void *)var_global + id);
    // pthread_exit((void *)(Valor de retorno));
}

int main(void)
{
    pthread_t threads[QTD_THREADS];
    int thread_return[QTD_THREADS];

    var_global = 0;

    printf("[main] iniciando thread principal...\n");

    printf("[main] criando %d threads...\n", QTD_THREADS);

    // Precisa ser long, pois vou usar como parâmetro na função pthread_create, e isso vai
    // facilitar o casting para void.
    for (long i = 0; i < QTD_THREADS; i++)
    {
        // pthread_create((Endereço thread), (ED para criação), (Função), (identificador para thread));
        pthread_create(&threads[i], NULL, funcao_thread, (void *)(i + 1));

        // Usar o uso de tipos da mesma forma que o professor, para manter a coerência de passagem
        // de parâmetros entre as funções.
    }

    //sleep(10);

    for (int i = 0; i < QTD_THREADS; i++)
    {
        printf("[main] aguardando termino da thread %d\n", (i + 1));
        pthread_join(threads[i], (void *)&thread_return[i]);
        // pthread_join((thread), (void *)(Endereço da variável que vai receber o valor));
        printf("[main] Thread %d retornou %d\n", (i + 1), thread_return[i]);
    }

    printf("[main] finalizando thread principal...\n");

    // Quando a função main(thread principal) é encerrada, todas outras threads são encerradas, então
    // para que minhas threads possam ser executadas corretamente é necessário que a função main espere
    // todas threads criadas serem finalizadas.

    return 0;
}