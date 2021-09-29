#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define QTD_PROCESSOS 30
#define QTD_THREADS 30

void *func_thread(void *param) {
    sleep(2);
    printf("Nova thread criada!\n");
}

void criaThreads() {
    clock_t t;
    pthread_t threads[QTD_THREADS];

    t = clock();

    for(int i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, func_thread, NULL); 
    }

    t = clock() - t;

    for (int i = 0; i < QTD_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Tempo de criação das threads: %ld\n", t);
}

int main(void) {

    clock_t t;
    int pid_pai = getpid();

    if(getpid() == pid_pai) {
        criaThreads();
    }

    t = clock();

    for (int i = 0; i < QTD_PROCESSOS; i++){
        if (getpid() == pid_pai) {
            printf("Novo processo criado!\n");
            sleep(2);
            fork();
            if(getpid() == pid_pai && i == QTD_PROCESSOS - 1) {
                t = clock() - t;
          
                printf("Tempo de criação dos processos: %ld\n", t);
            }
        }
    } 

    return 0;
}