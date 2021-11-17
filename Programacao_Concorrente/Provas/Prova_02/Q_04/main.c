#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define QTD_THREADS 10

int x = 0;
int y = 0;
int next = 0;
int number = 0;
int exec = 1;
// Não tem contenção de memória, pois o acesso é controlado por um array
int turn[QTD_THREADS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

void* add_number(void *p) {
    long index = (long)p;
    int valor;

    // A exclusão mútua é garantida pelo algorítmo, pois as threads só vão ter acesso a uma
    // das duas seções críticas após ter seu acesso liberado pelo protocolo de entrada.
    
    if((index % 2) == 0) {
        while (exec) {
            valor = 5 + rand() % 95;
            // Cada thread que entrar recebe um ticket
            turn[index] = __sync_fetch_and_add(&number, 1); //protocolo de entrada
            // Quando seu ticket que a thread recebeu for igual a next o acesso a seção crítica é liberada
            while (turn[index] != next)
                ;           //protocolo de entrada
            // secao critica [Inicio]
            x += valor;
            printf("[%ld - PAR] gerou %d\n", index, valor);
            usleep(200000); 
            // secao critica [Fim]
            next++; //protocolo de saida
        }
    } else {
        while (exec) {
            valor = 25 + rand() % 50;
            turn[index] = __sync_fetch_and_add(&number, 1);
            while (turn[index] != next)
                ;        
            y += valor;
            printf("[%ld - IMPAR] gerou %d\n", index, valor);
            usleep(300000);
            next++; 
        }
    }
}

int main() {
    time_t t;

    pthread_t threads[QTD_THREADS];
    
    for(long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, add_number, (void*)i);
    }

    srand((unsigned)time(&t));

    while((x+y) < 5000) {
        usleep(100);
    }

    exec = 0;

    printf("Soma: %d\n", x+y);
    printf("Finalizado\n");
    return 0;
}