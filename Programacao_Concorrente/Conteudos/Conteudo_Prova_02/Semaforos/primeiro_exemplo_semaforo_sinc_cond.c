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

sem_t arrive1, arrive2;

void *worker1(void *p)
{
    //worker task
    int sl = rand() % 5;
    sl++;
    printf("Worker 1: tarefa de %d segundos\n", sl);
    sleep(sl);
    printf("Worker 1 chegou na barreira\n");
    sem_post(&arrive1);
    sem_wait(&arrive2);
    printf("Worker 1 passou da barreira\n");
}

void *worker2(void *p)
{
    int sl = rand() % 5;
    sl++;
    printf("Worker 2: tarefa de %d segundos\n", sl);
    sleep(sl);
    printf("Worker 2 chegou na barreira\n");
    sem_post(&arrive2);
    sem_wait(&arrive1);
    printf("Worker 2 passou da barreira\n");
}

int main(void)
{

    time_t t;
    pthread_t thread1, thread2;

    sem_init(&arrive1, 0, 0);
    sem_init(&arrive2, 0, 0);

    srand(time(&t));

    pthread_create(&thread1, 0, worker1, 0);
    pthread_create(&thread2, 0, worker2, 0);

    pthread_join(thread1, 0);
    pthread_join(thread2, 0);

    return 0;
}