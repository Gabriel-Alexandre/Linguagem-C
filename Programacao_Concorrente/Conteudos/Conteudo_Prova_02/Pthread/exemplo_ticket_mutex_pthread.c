#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
/*
    int number = 1, next = 1, turn [1:n] = ([n] 0)

    process CS[i = 1 to n] {
        while(true) {
            // inicio protocolo de entrada 
            <turn[i] = number; number++>
            <await (turn[i] == next); >
            // fim protocolo de entrada 
            // secao critica
            <next++> // protocolo de saida
            // secao nao critica
        }
    }

*/

// Não foi tão bem explicado, depois tentar entender melhor se for necessário.
// Explicação melhor na aula do dia 27/10

#define QTD_THREADS 5

int varGlobal = 0;

int number = 1;
int next = 1;
int turn[QTD_THREADS];

pthread_mutex_t number_inc_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t condicao_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t condicao_cond = PTHREAD_COND_INITIALIZER;

void *cs(void *p)
{
    long idx = (long)p;
    while (1)
    {

        //turn[idx] = __sync_fetch_and_add(&number, 1); - ATOMICO

        pthread_mutex_lock(&number_inc_mutex);
        number++;
        turn[idx] = number;
        pthread_mutex_unlock(&number_inc_mutex);

        //        while (!(turn[idx] == next))
        //      ;
        pthread_mutex_lock(&condicao_mutex);
        if (turn[idx] % next == 0)
        {
            pthread_cond_signal(&condicao_cond);
        }
        else
        {
            pthread_cond_wait(&condicao_cond, &condicao_mutex);
        }
        varGlobal++;
        printf("[CS-%ld] Alterou o valor para: %d\n", idx, varGlobal);
        puts("..");
        pthread_mutex_lock(&number_inc_mutex);
        next++;
        turn[idx] = number;
        pthread_mutex_unlock(&number_inc_mutex);
        //__sync_fetch_and_add(&next, 1);
        pthread_mutex_unlock(&condicao_mutex);
    }

    return 0;
}

int main(void)
{
    pthread_t threads[QTD_THREADS];

    for (int i = 0; i < QTD_THREADS; i++)
        turn[i] = 0;

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, cs, (void *)i);
    }

    sleep(10);

    return 0;
}