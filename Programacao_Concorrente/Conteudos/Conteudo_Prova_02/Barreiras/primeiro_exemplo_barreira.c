#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

/*

process Worker[i = 1 to n] {
   while (true) {
      código da tarefa i;
      <count = count + 1;>
      <await (count == n);>
   }
}

*/

#define QTD_THREADS 5

int entrada[QTD_THREADS];
int saida[QTD_THREADS];
int contador;
// Como todas variáveis acessam o contador, no caso de muitas threads essa solução pode causa uma contenção de
// memória.

void *processa_parte(void *p)
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
        __sync_fetch_and_add(&contador, 1);
        while ((contador % QTD_THREADS) != 0)
            ;
    }
}

int main(void)
{

    pthread_t threads[QTD_THREADS];
    time_t t;

    contador = 0;

    srand((unsigned)time(&t));

    for (int i = 0; i < QTD_THREADS; i++)
    {
        entrada[i] = rand() % 100;
    }

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, processa_parte, (void *)i);
    }

    sleep(30);

    return 0;
}