#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

// Esse código exemplifica o problema de inconsistencia de memória ao fazer o acesso a memória
// compartilhada entre as threads (variável global). Como a função "var_global++" não é atômica
// (ou seja, não executa apenas uma instrução, pois "var_global++" == "var_global = var_global +1") 
// quando o escalonador estiver fazendo incrementos, pode acabar perdendo o valor de uma execução se
// se o valor de var_global for alterado muito rápidamente.

// Isso evidência os cuidados que devemos ter quando estamos lidando com a região crítica (Memória compartilhada)
// Uma da maneira de lidar é usando funções atômicas como "__sync_fetch_and_add(&var_global, 1)", mas essa maneira
// não resolve todos os problemas, é necessário tomar outros cuidados que vão ser evidênciados nos próximos códigos.

#define QTD_THREADS 500
#define QTD_ADD 100

long var_global;

void *funcao_thread(void *param)
{
    long id = (long)param;
    printf("[%ld] Thread criada!\n", id);

    for (int i = 0; i < QTD_ADD; i++)
    {   
        // Instrução que faz o incremento de forma atômica (Evitando a inconsistência de memória).
        __sync_fetch_and_add(&var_global, 1);
        // var_global++;
        //var_global = var_global + 1;
    }

    printf("[%ld] Thread finalizando...\n", id);
    pthread_exit((void *)var_global);
}

int main(void)
{
    pthread_t threads[QTD_THREADS];
    int result[QTD_THREADS];

    var_global = 0;

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, funcao_thread, (void *)i);
    }

    for (int i = 0; i < QTD_THREADS; i++)
    {
        pthread_join(threads[i], (void *)&result[i]);
        printf("[main] resultado recebido da thread %d: %d\n",
               i, result[i]);
    }

    printf("[main] Valor final da variavel global = %ld\n", var_global);

    return 0;
}