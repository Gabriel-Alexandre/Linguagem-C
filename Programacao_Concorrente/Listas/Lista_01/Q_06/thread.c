#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define QTD_THREADS 30

void *func_thread(void *param) {
    printf("Nova thread criada!\n");
    sleep(2);
}

int main(void) {

    pthread_t threads[QTD_THREADS];
    clock_t t;

    t = clock();

    for(int i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, func_thread, NULL); 
    }

    t = clock() - t;

    for (int i = 0; i < QTD_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Tempo de criação das threads: %ld\n", t);

    return 0;
}