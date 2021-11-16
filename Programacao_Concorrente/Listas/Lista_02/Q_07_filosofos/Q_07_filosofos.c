#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define QTD_FILOSOFOS 5
#define PENSANDO 4
#define COM_FOME 1
#define COMENDO 2

sem_t garfo[QTD_FILOSOFOS];
int estado[QTD_FILOSOFOS] = {PENSANDO, PENSANDO, PENSANDO, PENSANDO, PENSANDO};

void* filosofos(void *p) {
    long id = (long)p;
    
    if(id <= 3) {
        while(1) {
            estado[id] = COM_FOME;
            printf("Filosofo %ld com fome\n", id);

            // Pegando garfos
            sem_wait(&garfo[id]); // Esquerda
            sem_wait(&garfo[(id + 1) % QTD_FILOSOFOS]); // Direita
            estado[id] = COMENDO;
            printf("Filosofo %ld comendo\n", id);
            sleep(1);
            sem_post(&garfo[id]); // Esquerda
            sem_post(&garfo[(id + 1) % QTD_FILOSOFOS]); // Direita
            estado[id] = PENSANDO;
            printf("Filosofo %ld pensando\n", id);
            usleep(150);
        }
    } else {
        while(1) {

            estado[id] = COM_FOME;
            printf("Filosofo %ld com fome\n", id);

            // Pegando garfos
            sem_wait(&garfo[0]); // Esquerda
            sem_wait(&garfo[id]); // Direita
            estado[id] = COMENDO;
            printf("Filosofo %ld comendo\n", id);
            sleep(1);
            sem_post(&garfo[0]); // Esquerda
            sem_post(&garfo[id]); // Direita
            estado[id] = PENSANDO;
            printf("Filosofo %ld pensando\n", id);
            usleep(150);
        }
    }
}

int main() {
    pthread_t filosofo[QTD_FILOSOFOS];

    for(int i = 0; i < QTD_FILOSOFOS; i++) {
        sem_init(&garfo[i], 0, 1);
    }

    for(long i = 0; i < QTD_FILOSOFOS; i++) {
        pthread_create(&filosofo[i], 0, filosofos, (void *)i);
    }

    sleep(8);

    return 0;
}