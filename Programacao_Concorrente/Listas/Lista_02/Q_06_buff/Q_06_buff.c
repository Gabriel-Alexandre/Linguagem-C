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
sem_t mutexF, mutexD;
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
    char result;

    char aux[6];
    aux[0] = index;

    strcat(aux, ".txt");

    FILE *arq;
    arq = fopen(aux, "w");

    while(exec) {
        sem_wait(&full);
        sem_wait(&mutexF);
        result = buffer[front];
        front = (front + 1) % TAM_BUFFER;
        fprintf(arq,"%c", result);
        __sync_fetch_and_add(&contador, 1);
        printf("[CONS-%ld] Consumiu o valor %c (%d)\n", index-65, result, contador);
        usleep(65 + rand() % 100);
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

    sem_init(&empty, 0, TAM_BUFFER); // empty = 1
    sem_init(&full, 0, 0);           //full = 0
    sem_init(&mutexD, 0, 1);
    sem_init(&mutexF, 0, 1);

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
    printf("exec: %d\n", exec);

    FILE *write;
    write = fopen("result.txt", "w");
    char aux[6];
    char linha[4096];
    for(int i = 0; i < QTD_CONS; i++) {
        FILE *read;
        sleep(5);

        aux[0] = i+65;

        strcat(aux, ".txt");
        read = fopen(aux, "r");
        printf("%s\n", aux);
        
        //fgets(linha, 4096, read);
        fread(linha, sizeof(linha),1,read);
        printf("%s\n\n\n", linha);
        
        fprintf(write, "%s", linha);

        fclose(read);
        for(int i = 0; i < 4096; i++) {
          linha[i] = 0;
        }

        for(int i = 0; i < 6; i++) {
            aux[i] = 0;
        }
    }

    // - Ele está escrevendo corretamente. (Aquilo que é lido é escrito corretamente).
    // - Há um problema na condição de parada 'exec' das threads.
    // - Há um problema na leitura das threads.

    fclose(write);

    return 0;
}
