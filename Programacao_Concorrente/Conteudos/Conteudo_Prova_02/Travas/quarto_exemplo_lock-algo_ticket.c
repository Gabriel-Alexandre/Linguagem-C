#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

/*

int number = 1, next = 1, turn[1:n] = ([n] 0)
n - numero de threads

process CS[i = 1 to n] {
    while (true) {
        turn[i] = FA(number, 1); - protocolo de entrada
        while (turn[i] != next); - protocolo de entrada
        //secao critica
        next = next + 1;         - protocolo de saida
        //secao nao critica

    }

}

*/

// Esse algorítmo fornece uma solução justa sem problamas, pois garante o acesso correto a seção crítica, obedecendo
// a todos propriedades necessárias.

#define QTD_THREADS 5

int var_global = 0;
int number = 0;
int next = 0;
int turn[QTD_THREADS] = {0, 0, 0, 0, 0}; // Não tem contenção de memória, pois o acesso é controlado por um array

void *funcao_secao_critica(void *p)
{
    long id = (long)p;
    while (1)
    {
        // Cada thread que entrar recebe um ticket
        turn[id] = __sync_fetch_and_add(&number, 1); //protocolo de entrada
        // Quando seu ticket for igual ao ticket o acesso a seção crítica é liberada
        while (turn[id] != next)
            ;         //protocolo de entrada
        var_global++; //secao critica
        printf("[%ld] var_global = %d\n", id, var_global);
        sleep((rand() % 3) + 1);
        // Quando a execução da seção crítica é encerrado, é liberado o acesso para o próximo ticket
        next++; //protocolo de saida
    }
}

int main(void)
{
    pthread_t threads[QTD_THREADS];

    // A ordem das threads vai depender de como o escalonador vai escalonar as threads
    // Depois ele vai obdecer a ordem de chegada no protocolo de entrada
    printf("[main] Algoritmo do ticket - %d threads\n", QTD_THREADS);
    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, funcao_secao_critica, (void *)i);
    }

    // Nesse exemplo o algorítmo não vai terminar, pois é um looping infinito
    for (int i = 0; i < QTD_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}