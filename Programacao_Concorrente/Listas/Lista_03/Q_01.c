#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define QTD_PROD 2
#define QTD_CONS 3
#define TAM_BUFFER 256

char buffer[TAM_BUFFER];

sem_t empty, full;
sem_t mutexF, mutexD;
int front = 0, rear = 0;
int contador = 0;
int exec = 1;

void *producer(void *p)
{
    long index = (long)p;
    unsigned char data;

    while(exec) {
        data = rand() % 256;
        sem_wait(&empty);
        sem_wait(&mutexD);
        buffer[rear] = data;
        rear = (rear + 1) % TAM_BUFFER;
        printf("[PROD-%ld] Gerou valor '%c'\n", index, data);
        usleep(150);
        sem_post(&mutexD);
        sem_post(&full);
    }
}

void *consumer(void *p)
{
    long index = (long)p + 65;
    char result[2];

    char aux[6];
    aux[0] = index;

    strcat(aux, ".txt");

    FILE *arq;
    arq = fopen(aux, "w");

    while(exec) {
        sem_wait(&full);
        sem_wait(&mutexF);
        result[0] = buffer[front];
        result[1] = '\n';
        front = (front + 1) % TAM_BUFFER;
        fprintf(arq,"%d", result[0]);
        fprintf(arq,"%c", result[1]);
        __sync_fetch_and_add(&contador, 1);
        printf("[CONS-%ld] Consumiu o valor %c (%d)\n", index-65, result[0], contador);
        usleep(50 + rand() % 51);
        sem_post(&mutexF);
        sem_post(&empty);
    }

    fclose(arq);
}

int main(void)
{
    time_t t;

    pthread_t produtores[QTD_PROD];
    pthread_t consumidores[QTD_CONS];

    sem_init(&empty, 0, TAM_BUFFER);
    sem_init(&full, 0, 0);
    sem_init(&mutexD, 0, 1);
    sem_init(&mutexF, 0, 1);

    srand((unsigned)time(&t));

    for (long i = 0; i < QTD_PROD; i++) {
        pthread_create(&produtores[i], 0, producer, (void *)i);
    }

    for (long i = 0; i < QTD_CONS; i++) {
        pthread_create(&consumidores[i], 0, consumer, (void *)i);
    }

    while (contador < (TAM_BUFFER * 4)) {
        usleep(100);
    }

    exec = 0;
    printf("exec: %d\n", exec);

    return 0;
}
