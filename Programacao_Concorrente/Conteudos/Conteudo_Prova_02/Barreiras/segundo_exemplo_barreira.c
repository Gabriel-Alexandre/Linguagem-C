#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define QTD_THREADS 5

int entrada[QTD_THREADS];
int saida[QTD_THREADS];

int arrive[QTD_THREADS];
int proceed[QTD_THREADS];

// Responsável por executar as terefas
void *worker(void *p)
{
    long id = (long)p;
    while (1)
    {
        /* codigo da tarefa */
        printf("[%ld] iniciando tarefa...\n", id);
        saida[id] = pow(entrada[id], 2); //processamento
        printf("[%ld] Tarefa: %d\n", id, entrada[id]);
        printf("[%ld] Resultado tarefa: %d\n", id, saida[id]);
        sleep((int)(rand() % 3));
        printf("[%ld] Embarreirada, esperando as demais\n", id);
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
    time_t t;

    srand((unsigned)time(&t));

    for (int i = 0; i < QTD_THREADS; i++)
    {
        entrada[i] = rand() % 100;
    }

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, worker, (void *)i);
    }
    pthread_create(&coord, NULL, coordinator, NULL);

    sleep(45);

    return 0;
}