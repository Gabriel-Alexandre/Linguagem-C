#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define QTD_THREADS 10

int x = 0;
int y = 0;
int exec = 1;

// Responsável por garantir o sincronismo condicional, e garantir que cada thread só voltará a ser executada apenas
// quando todas a outras também forem executadas.
sem_t arrive[QTD_THREADS];
// Responsável por garantir a exclusão mútua
sem_t mutex;

void* add_number(void *p) {
    long index = (long)p;
    int valor;

    // Verifica se a thread é impar ou par
    if(index % 2 == 0) {
        while(exec) {
            valor = 5 + rand() % 96; // gera valor aleatório
            sem_wait(&mutex); // protocolo de entrada
            x += valor;
            printf("[%ld - PAR] gerou %d\n", index, valor);
            usleep(200000);
            sem_post(&mutex); // protocolo de saida
            sem_post(&arrive[index]); // sinalização que terminou sua execução

            // ponto de embarreiramento
            for(int i = 0; i < QTD_THREADS; i++) {   
                if (i != index) {
                    int sem_v;
                    sem_getvalue(&arrive[i], &sem_v);
                    if (sem_v != 0)
                        sem_wait(&arrive[i]);
                }
            }
        }
    } else {
        while(exec) {
            valor = 25 + rand() % 51;
            sem_wait(&mutex);
            y += valor;
            printf("[%ld - IMPAR] gerou %d\n", index, valor);
            usleep(300000);
            sem_post(&mutex);
            sem_post(&arrive[index]);

            for (int i = 0; i < QTD_THREADS; i++) {   
                if (i != index) {
                    int sem_v;
                    sem_getvalue(&arrive[i], &sem_v);
                    if (sem_v != 0)
                        sem_wait(&arrive[i]);
                }
            }
        }
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));

    pthread_t threads[QTD_THREADS];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < QTD_THREADS; i++) {
        sem_init(&arrive[i], 0, 0);
    }
    
    for(long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, add_number, (void*)i);
    }

    // Condição de parada -> Quando X + Y == 5000
    while((x+y) < 5000) {
        usleep(100);
    }

    exec = 0;

    printf("Soma: %d\n", x+y);
    printf("Finalizado\n");
    return 0;
}