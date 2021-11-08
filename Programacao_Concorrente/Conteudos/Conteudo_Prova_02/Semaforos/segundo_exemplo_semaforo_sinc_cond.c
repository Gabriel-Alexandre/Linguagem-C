#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

/*

sem arrive1 = 0, arrive2 = 0;

process Worker1 {
    ...
    worker task
    V(arrive1);  sinaliza chegada na barreira 
    P(arrive2);  aguarda a thread 2
    ...
}

process Worker2 {
    ...
    worker task
    V(arrive2); sinaliza chegada na barreira
    P(arrive1); aguarda a thread 1
    ...
}


*/

#define QTD_THREADS 5

sem_t arrive[QTD_THREADS];

void *worker(void *p)
{
    long index = (long)p;
    //worker task
    int sl = rand() % 5;
    sl++;
    printf("Worker %ld: tarefa de %d segundos\n", index, sl);
    sleep(sl);
    printf("Worker %ld chegou na barreira\n", index);
    sem_post(&arrive[index]);

    for (int i = 0; i < QTD_THREADS; i++)
    {
        if (i != index)
        {
            int sem_v;
            sem_getvalue(&arrive[i], &sem_v);
            if (sem_v != 0)
                sem_wait(&arrive[i]);
        }
    }

    printf("Worker %ld passou da barreira\n", index);
}

int main(void)
{

    time_t t;
    pthread_t threads[QTD_THREADS];

    for (int i = 0; i < QTD_THREADS; i++)
    {
        sem_init(&arrive[i], 0, 0);
    }

    srand(time(&t));

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], 0, worker, (void *)i);
    }

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_join(threads[i], 0);
    }

    return 0;
}