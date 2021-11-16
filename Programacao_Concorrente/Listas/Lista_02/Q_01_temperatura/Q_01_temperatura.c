#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>

int var_global_temperatura = 600;
int exec = 1;
int contador = 0;

sem_t mutex1, mutex2, mutex3;

void* add_temperatura_01(void *p) {
    int data;

    while(exec) {
        data = -10 + rand() % 60;
        sem_wait(&mutex1);
        var_global_temperatura += data;
        printf("[Thread 1] temperatura: %d\n", var_global_temperatura);
        usleep(300);
        sem_post(&mutex1);
    }
}

void* add_temperatura_02(void *p) {
    int data;

    while(exec) {
        data = -20 + rand() % 40;
        sem_wait(&mutex2);
        var_global_temperatura += data;
        printf("[Thread 2] temperatura: %d\n", var_global_temperatura);
        usleep(400);
        sem_post(&mutex2);
    }
}

void* verifica_temperatura(void *p) {
    while(exec) {
      while(var_global_temperatura < 1000);

      sem_wait(&mutex3);
      __sync_fetch_and_add(&contador, 1);
      var_global_temperatura = 600;
      printf("contador: %d\n", contador);
      sem_post(&mutex3);
    }
}

int main() {
    time_t t;

    pthread_t thread1, thread2, thread3;

    sem_init(&mutex1, 0, 1);
    sem_init(&mutex2, 0, 1);
    sem_init(&mutex3, 0, 1);
    
    pthread_create(&thread1, NULL, add_temperatura_01, NULL);
    pthread_create(&thread2, NULL, add_temperatura_02, NULL);
    pthread_create(&thread3, NULL, verifica_temperatura, NULL);


    srand((unsigned)time(&t));

    while(contador < 5) {
        usleep(100);
    }

    exec = 0;
    sem_close(&mutex1);
    sem_destroy(&mutex1);
    sem_close(&mutex2);
    sem_destroy(&mutex2);
    sem_close(&mutex3);
    sem_destroy(&mutex3);

    printf("Finalizando\n");
    return 0;
}