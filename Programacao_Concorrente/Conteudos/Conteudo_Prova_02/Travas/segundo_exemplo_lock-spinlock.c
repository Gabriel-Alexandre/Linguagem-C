#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int lock;
int var_global;

// Garante que apenas uma thread vai ser executada por vez, porém não garante que as threads vão se alternar, ou seja,
// não garante que todas as threads vão ter acesso a seção crítica.

void *cs1(void *p)
{
    while (1)
    {
        //< await (!lock) lock = 1; > //protocolo de entrada
        /* protocolo de entrada */
        //type __sync_lock_test_and_set (type *ptr, type value, ...)

        while (__sync_lock_test_and_set(&lock, 1))
            ; //so progride quando in2 for diferente de 1
        //lock = 1;
        /* protocolo de entrada */
        printf("cs1 na secao critica!\n");
        var_global++;
        sleep(1);
        printf("cs1: valor de var_global: %d\n", var_global);
        lock = 0; //protocolo de saida
        printf("cs1 fora da secao critica!\n");
        sleep(1);
    }
}

void *cs2(void *p)
{
    while (1)
    {
        //< await (!lock) lock = 1; > //protocolo de entrada
        /* protocolo de entrada */
        while (__sync_lock_test_and_set(&lock, 1))
            ; //so progride quando in1 for diferente de 1
        /* protocolo de entrada */
        printf("cs2 na secao critica!\n");
        var_global++;
        sleep(1);
        printf("cs2: valor de var_global: %d\n", var_global);
        lock = 0; //protocolo de saida
        printf("cs2 fora da secao critica!\n");
        sleep(1);
    }
}
int main(void)
{
    pthread_t thread1, thread2;
    lock = 0;

    var_global = 0;

    pthread_create(&thread1, NULL, cs1, NULL);
    pthread_create(&thread2, NULL, cs2, NULL);

    sleep(20);

    return 0;
}