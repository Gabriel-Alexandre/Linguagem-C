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

typedef struct {
    unsigned char buffer[TAM_BUFFER];
    sem_t mutexF, mutexD;
    sem_t empty, full;
    int front, rear;
    int contador;
} Q_Buffer;

int exec = 1, contador = 0;

Q_Buffer b;

void init(Q_Buffer *b) {
    sem_init(&b->empty, 0, TAM_BUFFER);
    sem_init(&b->full, 0, 0);
    sem_init(&b->mutexD, 0, 1);
    sem_init(&b->mutexF, 0, 1);
    b->front = 0;
    b->rear = 0;
}

void gera_dado(Q_Buffer *b, unsigned char data, long i) {

    sem_wait(&b->empty);
    sem_wait(&b->mutexD);
    b->buffer[b->rear] = data;
    b->rear = (b->rear + 1) % TAM_BUFFER;
    printf("[PROD-%ld] Gerou valor '%c'\n", i, data);
    usleep(150);
    sem_post(&b->mutexD);
    sem_post(&b->full);
}

void consome_dado(Q_Buffer *b,  FILE *arq, long i) {
    char result[2];
    sem_wait(&b->full);
    sem_wait(&b->mutexF);
    result[0] = b->buffer[b->front];
    result[1] = '\n';
    b->front = (b->front + 1) % TAM_BUFFER;
    fprintf(arq,"%d", result[0]);
    fprintf(arq,"%c", result[1]);
    __sync_fetch_and_add(&b->contador, 1);
    printf("[CONS-%ld] Consumiu o valor %c (%d)\n", i-65, result[0], contador);
    usleep(50 + rand() % 51);
    sem_post(&b->mutexF);
    sem_post(&b->empty);
}

void *producer(void *p)
{
    long index = (long)p;
    unsigned char data;

    while(exec) {
        data = rand() % 256;
        gera_dado(&b, data, index);
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
        consome_dado(&b, arq, index);
        __sync_fetch_and_add(&contador, 1);
    }

    fclose(arq);
}

int main(void)
{
    time_t t;

    pthread_t produtores[QTD_PROD];
    pthread_t consumidores[QTD_CONS];

    init(&b);

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
