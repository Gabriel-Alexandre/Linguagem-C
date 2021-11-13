#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

/*
typeT buf[n];

int front = 0, rear = 0;
sem empty = n, full 0;
sem mutexDep = 1, mutexFetch = 1;

process producer {
    while(true) {
        //produz dado
        P(empty);
        P(mutexDep);
        buf[rear] = data;        
        rear = (rear + 1) % n;
        V(mutexDep);
        V(full);
    }
}

process consumer {
    while (true) {
        P(full);
        P(mutexFetch);
        result = buf[front];
        front = (front + 1) % n;
        V(mutexFetch);
        V(empty);
    }
}

*/

#define QTD_PROD 2
#define QTD_CONS 4
#define TAM_BUFFER 20

int buffer[TAM_BUFFER];

sem_t empty, full;
sem_t mutexF, mutexD;

int front = 0, rear = 0;
int contador = 0;

void *producer(void *p)
{
    long index = (long)p;
    int data;
    printf("[PROD-%ld] Iniciando...\n", index);
    while (1)
    {
        data = rand() % 255;
        sem_wait(&empty);
        sem_wait(&mutexD);
        buffer[rear] = data;
        rear = (rear + 1) % TAM_BUFFER;
        contador++;
        printf("[PROD-%ld] Gerou valor %d (%d)\n", index, data, contador);
        sleep(1);
        sem_post(&mutexD);
        sem_post(&full);
    }
}

void *consumer(void *p)
{
    long index = (long)p;
    int result;
    printf("[CONS-%ld] Iniciando...\n", index);
    while (1)
    {
        sem_wait(&full);
        sem_wait(&mutexF);
        result = buffer[front];
        front = (front + 1) % TAM_BUFFER;
        printf("[CONS-%ld] Consumiu o valor %d\n", index, result);
        sleep(1);
        sem_post(&mutexF);
        sem_post(&empty);
    }
}

int main(void)
{
    time_t t;

    pthread_t produtores[QTD_PROD];
    pthread_t consumidores[QTD_CONS];

    sem_init(&empty, 0, TAM_BUFFER); // empty = 1
    sem_init(&full, 0, 0);           //full = 0
    sem_init(&mutexD, 0, 1);
    sem_init(&mutexF, 0, 1);

    srand((unsigned)time(&t));

    for (long i = 0; i < QTD_PROD; i++)
    {
        pthread_create(&produtores[i], 0, producer, (void *)i);
    }

    for (long i = 0; i < QTD_CONS; i++)
    {
        pthread_create(&consumidores[i], 0, consumer, (void *)i);
    }

    sleep(30);

    printf("Thread principal finalizando...\n");

    return 0;
}
