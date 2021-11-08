#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/*

sem mutex = 1;

process cs[i = 1 to n] {
    while (true) {
        P(mutex);
        secao critica
        V(mutex);
        secao nao critica

    }
}

*/

// O funcionamento das funções do semafor estão explicados nos slides.

#define QTD_THREADS 5

sem_t mutex;

int var_global = 0;

int repeat = 1;

void *cs(void *p)
{
    long index = (long)p;
    printf("[%ld] Iniciando... \n", index);
    while (repeat)
    {
        sem_wait(&mutex); 
        var_global++;
        printf("[%ld] Alterou var_global para %d\n", index, var_global);
        sleep(1);
        sem_post(&mutex);
        sleep(1);
    }
    printf("[%ld] Finalizando... \n", index);
}

int main(void)
{

    pthread_t threads[QTD_THREADS];

    sem_init(&mutex, 0, 1); //mutex = 1

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], 0, cs, (void *)i);
    }

    sleep(20);

    repeat = 0;

    sleep(5);

    sem_close(&mutex);
    sem_destroy(&mutex);

    return 0;
}