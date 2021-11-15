#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define QTD_THREADS 10
#define PARTE_IMG 256

// O mais importante é compreender como o problema do sincronismo condicional é resolvido a partir
// desse modelo de solução, no qual é implementado uma barreira usando espera ocupada.

int imagem[QTD_THREADS][PARTE_IMG];
// Não entendi ao certo como fazer o processamento da imagem, então fiz apenas um exemplo

int arrive[QTD_THREADS];
int proceed[QTD_THREADS];

// Responsável por executar as terefas
void *worker(void *p)
{
    long id = (long)p;
    int parte_imagem[PARTE_IMG];

    while (1)
    {
        /* codigo do processamento da imagem */
        imagem[id][0] = 1;
        /* fim codigo tarefa */
        /* ponto de embarreiramento */
        arrive[id] = 1;
        while (proceed[id] != 1)
            usleep(3000); //descanso para a espera ocupada
        proceed[id] = 0;
        printf("[%ld] Saindo da barreira...\n", id);
    }

    return 0;
}

// Responsável por controlar a barreira
void *coordinator(void *p)
{
    while (1)
    {
        // Esse for só vai deixar de ser executado quando todas as threads finalizarem sua tarefa
        for (int i = 0; i < QTD_THREADS; i++)
        {
            while (arrive[i] == 0)
                usleep(3000); //descanso para a espera ocupada
            arrive[i] = 0;
        }

        printf("[coord] Barreira cheia, liberando...\n");
        // Esse for é responsável por liberar o embarreiramento
        for (int i = 0; i < QTD_THREADS; i++)
        {
            proceed[i] = 1;
        }
    }

    return 0;
}

int main(void)
{
    pthread_t threads[QTD_THREADS];
    pthread_t coord;

    for (long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, (void *)i);
    }

    pthread_create(&coord, NULL, coordinator, NULL);

    sleep(45);

    return 0;
}