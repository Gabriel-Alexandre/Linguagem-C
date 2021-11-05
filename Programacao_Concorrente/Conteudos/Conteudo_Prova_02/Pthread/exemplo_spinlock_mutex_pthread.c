#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

/*

bool lock = false;

process CS[i=1 to n] {
    while(true) {
        <await (!lock) lock = true> // protocolo de entrada
        // secao critica
        lock = false; // protocolo de saida
        // secao nao critica
    }
}
*/

// Explicação melhor na aula do dia 27/10

int lock = 0;
int varGlobal = 0;

pthread_mutex_t mutex_lock_control = PTHREAD_MUTEX_INITIALIZER;
// inicializacao da variavel de controle mutex

void *cs(void *p)
{
    long idx = (long)p;
    printf("[CS-%ld] Iniciando...\n", idx);
    while (1)
    {
        /*
        while (__sync_lock_test_and_set(&lock, 1))
            ; // protocolo de entrada
        */

        pthread_mutex_lock(&mutex_lock_control); // protocolo de entrada

        // inicio da secao critica
        varGlobal++;
        printf("[CS-%ld] Alterou o valor para: %d\n", idx, varGlobal);
        puts("..");
        usleep(900000);
        //sleep(1); //DESCOMENTE PARA GERAR STARVATION
        // SO THREAD 0 ACESSARA A SESSAO CRITICA

        // fim da secao critica

        /*
        lock = 0; // protocolo de saida
        */
        pthread_mutex_unlock(&mutex_lock_control); // protocolo de saida
    }

    return 0;
}

int main(void)
{
    pthread_t threads[5];

    for (long i = 0; i < 5; i++)
        pthread_create(&threads[0], NULL, cs, (void *)i);

    sleep(20);

    return 0;
}