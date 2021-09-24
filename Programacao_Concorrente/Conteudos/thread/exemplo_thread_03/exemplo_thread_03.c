#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

// O propósito desse exemplo é mostra como podemos passar mais parâmetros para a função
// que irá executar a thread, utilizando o "struct" como ferramenta.

#define QTD_THREADS 5

typedef struct
{
    int index;
    char type;
    int data_chunk;
} pedaco_imagem;

void *processa_estrutura(void *param)
{
    pedaco_imagem *meu_pedaco;
    meu_pedaco = (pedaco_imagem *)param;
    long processed;

    printf("[%d] type: %c\n", meu_pedaco->index, meu_pedaco->type);
    printf("[%d] data chunk: %d\n", meu_pedaco->index, meu_pedaco->data_chunk);
    printf("processing...\n");
    processed = (int)pow((double)meu_pedaco->data_chunk, (double)2);
    sleep(rand() % 10 + meu_pedaco->index);
    printf("[%d] processed data chunk = %ld\n", meu_pedaco->index,
           processed);
    pthread_exit((void *)processed);
}

int main(void)
{
    time_t t;

    pedaco_imagem imagem[QTD_THREADS];
    pthread_t threads[QTD_THREADS];
    int result[QTD_THREADS];

    srand((unsigned)time(&t));

    for (int i = 0; i < QTD_THREADS; i++)
    {
        imagem[i].index = i + 1;
        imagem[i].type = 65 + i;
        imagem[i].data_chunk = rand() % 255;
    }

    for (int i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, processa_estrutura,
                       (void *)&imagem[i]);
    }

    for (int i = 0; i < QTD_THREADS; i++)
    {
        pthread_join(threads[i], (void *)&result[i]);
        printf("[main] resultado recebido da thread %d: %d\n",
               i, result[i]);
    }

    return 0;
}