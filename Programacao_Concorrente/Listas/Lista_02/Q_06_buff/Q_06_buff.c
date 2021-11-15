#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define QTD_PROD 2
#define QTD_CONS 4
#define TAM_BUFFER 1024

char buffer[TAM_BUFFER];

sem_t empty, full;
int front = 0, rear = 0;
int contador = 0;
int exec = 1;

void *producer(void *p)
{
    long index = (long)p;
    char data;

    while(exec) {
        data = 65 + rand() % 25;
        sem_wait(&empty);
        buffer[rear] = data;
        rear = (rear + 1) % TAM_BUFFER;
        printf("[PROD-%ld] Gerou valor '%c'\n", index, data);
        usleep(150);
        sem_post(&full);
    }
}

void *consumer(void *p)
{
    long index = (long)p + 65;
    char result;

    char aux[6];
    aux[0] = index;

    strcat(aux, ".txt");

    FILE *arq;
    arq = fopen(aux, "wt");

    while(exec) {
        sem_wait(&full);
        result = buffer[front];
        front = (front + 1) % TAM_BUFFER;
        fprintf(arq,"%c", result);
        __sync_fetch_and_add(&contador, 1);
        printf("[CONS-%ld] Consumiu o valor %c (%d)\n", index-65, result, contador);
        usleep(65 + rand() % 100);
        sem_post(&empty);
    }

    fclose(arq);
}

int main(void)
{
    time_t t;

    pthread_t produtores[QTD_PROD];
    pthread_t consumidores[QTD_CONS];

    sem_init(&empty, 0, TAM_BUFFER); // empty = 1
    sem_init(&full, 0, 0);           //full = 0

    srand((unsigned)time(&t));

    for (long i = 0; i < QTD_PROD; i++) {
        pthread_create(&produtores[i], 0, producer, (void *)i);
    }

    for (long i = 0; i < QTD_CONS; i++) {
        pthread_create(&consumidores[i], 0, consumer, (void *)i);
    }

    while (contador < 4096) {
        usleep(100);
    }

    exec = 0;

    FILE *read, *write;
    write = fopen("result.txt", "wt");
    char aux[6];
    char linha[4096];
    for(int i = 0; i < QTD_CONS; i++) {

        aux[0] = i+65;

        strcat(aux, ".txt");
        read = fopen(aux, "rt");
        printf("%s\n", aux);

        fgets(linha, 4096, read);
        linha[strlen(linha)-1] = '\0';
        
        fprintf(write, "%s", linha);

        fclose(read);

        for(int i = 0; i < 6; i++) {
            aux[i] = 0;
        }
    }

    fclose(write);

    return 0;
}
