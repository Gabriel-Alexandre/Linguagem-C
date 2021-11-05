#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

/*
prcess Worker[i = 1 to n ] {
    while (true) {
        //tarefa i
        <count = count + 1>
        <await (count == n)>
    }
}

*/

// Explicação melhor na aula do dia 27/10

#define QTD_THREADS 5

int contador_barreira = 0;

pthread_barrier_t controle_barreira;

void *worker(void *p)
{
    long idx = (long)p;

    while (1)
    {

        printf("Thread %d vai fazer sua tarefa\n", idx);
        puts("..");

        sleep(1 + idx); //simula uma tarefa

        printf("Thread %d - terminou a tarefa, chegou na barreira\n", idx);
        puts("..");

        int wait_ret = pthread_barrier_wait(&controle_barreira);

        if ((wait_ret != 0) && (wait_ret != PTHREAD_BARRIER_SERIAL_THREAD))
        {
            printf("BARRIER ERROR!\n");
            exit(0);
        }

        /*
        __sync_fetch_and_add(&contador_barreira, 1); //INCREMENTO ATOMIC

        printf("[%d] CONTADOR BARREIRA: %d\n", idx, contador_barreira);
        puts("..");

        while (contador_barreira % QTD_THREADS != 0)
            ;

        */

        printf("Thread %d - passou da barreira\n", idx);
        puts("..");
    }
}

int main(void)
{

    pthread_t threads[QTD_THREADS];

    int init_bar_ret = pthread_barrier_init(&controle_barreira, NULL, QTD_THREADS);

    if (init_bar_ret != 0)
    {
        printf("PTHREAD_BARRIER init error!\n");
        // if (init_bar_ret == EINVAL)
        // variavel de atributos passada para o init invalida
        // ou contador de threads igual a zero
        // if (init_bar_ret == EINVAL)
        // ENOMEM - nao ha memoria disponivel
        // EAGAIN - nao ha recursos para criacao da barreira
        exit(0);
    }

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, worker, (void *)i);
    }

    sleep(30);

    printf("Thread main vai finalizar!\n");
    puts("..");

    return 0;
}