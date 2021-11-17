#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>

#define QTD_THREADS 10

int x = 0;
int y = 0;
int next = 0;
int exec = 1;

// O controle da seção crítica é realizado com uma lógica semelhante ao algorítmo do ticket, porém
// adaptado ao uso de semáforos, no qual o objetivo é garantir que todos as threads acessem a 
// seção crítica, assim como apenas um thread acesse por vez.

// Quando as threas chegam no protocólo de entrada, seu valor é 1, assim sendo, só a primeira thread passa,
// e as demais ficam bloqueadas de acordo com a ordem que chegaram.

// Quando um thread termina de executar a seção crítica, ela libera o acesso para a próxima thread. Esse
// comportamento se repete até que a condição de parada seja acionada.
sem_t ticket[QTD_THREADS];

void* add_number(void *p) {
    long index = (long)p;
    int valor;

    // Identifica se a thread e par ou impar
    if((index % 2) == 0) {
        while(exec) {
            valor = 5 + rand() % 95;
            sem_wait(&ticket[next]); // Protocolo de entrada
            x += valor;
            printf("[%ld - PAR] gerou %d\n", index, valor);
            next = (next + 1) % QTD_THREADS;        // Seção crítica
            usleep(200000);
            sem_post(&ticket[next]); // Protocolo de saída
        }
    } else {
        while(exec) {
        valor = 25 + rand() % 50;
        sem_wait(&ticket[next]);
        y += valor;
        printf("[%ld - IMPAR] gerou %d\n", index, valor);
        next = (next + 1) % QTD_THREADS;
        usleep(300000);
        sem_post(&ticket[next]);
        }
    }
}

int main() {
    time_t t;

    pthread_t threads[QTD_THREADS];

    for(int i = 0; i < QTD_THREADS; i++) {
        sem_init(&ticket[i], 0, 1);
    }
    
    for(long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, add_number, (void*)i);
    }

    srand((unsigned)time(&t));

    // Condição de parada -> Quando X + Y == 5000
    while((x+y) < 5000) {
        usleep(100);
    }

    exec = 0;
    
    for(int i=0;i< QTD_THREADS; i++) {
        sem_close(&ticket[i]);
        sem_destroy(&ticket[i]);
    }

    printf("Soma: %d\n", x+y);
    printf("Finalizado\n");
    return 0;
}