#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define QTD_ESCREVER 5
#define QTD_LER 5
#define COND_PARADA 256

// Definição do módulo
typedef struct {
    sem_t mutexF, mutexD;
} Q_Buffer;

int contador = 0;

Q_Buffer b;

// Função para iniciar os semaforos responsáveis controle de exclusão mutua
void init(Q_Buffer *b) {
    sem_init(&b->mutexD, 0, 1);
    sem_init(&b->mutexF, 0, 1);
}

// Função responsável por escrever dado
void escreve_dado(Q_Buffer *b, FILE *arq, unsigned char data, long i) {
    // Escreve valor aleatório gerado recebido e adiciona uma quebra de linha
    char result[2];
    sem_wait(&b->mutexD);
    result[0] = data;
    result[1] = '\n';
    fprintf(arq,"%d", result[0]);
    fprintf(arq,"%c", result[1]);
    printf("[Escritor-%ld] Gerou valor '%d'\n", i, data);
    usleep(15000);
    sem_post(&b->mutexD);
    __sync_fetch_and_add(&contador, 1);
}

// Função responsavel por ler dado
void le_dado(Q_Buffer *b,  FILE *arq, long i) {
    // Lê dado enquando existe linha no arquvivo e printa cada linha lida
    char linha[100];
    sem_wait(&b->mutexF);
    while(!feof(arq)) {
        fgets(linha, 100, arq);
        printf("[Leitor-%ld] Leu valor %s", i-49, linha);
    }
    usleep(50000 + rand() % 50001);
    sem_post(&b->mutexF);
}

// Thread de escrita
void *thread_escreve(void *p) {
    long index = (long)p;
    unsigned char data;

    char aux[6] = " ";
    aux[0] = index + 49;

    strcat(aux, ".txt");

    // Cria o arquivo de acordo com o id da thread
    FILE *arq;
    arq = fopen(aux, "w");

    while(contador < COND_PARADA) {
        // Gera um valor aleatório e chama a função de escrita
        data = rand() % 256;
        escreve_dado(&b, arq, data, index);
    }

    fclose(arq);
}

// Thread de leitura
void *thread_le(void *p) {
    long index = (long)p + 49;
    char result[2];

    char aux[6] = " ";
    aux[0] = index;

    strcat(aux, ".txt");

    // Abre o arquivo de acordo com o id da thread
    FILE *arq;
    arq = fopen(aux, "r");

    // Chama a função de leitura
    le_dado(&b, arq, index);

    fclose(arq);
}

int main(void)
{
    time_t t;

    pthread_t escreve[QTD_ESCREVER];
    pthread_t ler[QTD_LER];

    init(&b);

    srand((unsigned)time(&t));

    // Primeiro as threads de escrita, geram dados aleatórios entre 0 e 255, e escrevem nos arquivos.
    // Cada thread é responsável pela escrita de um arquivo diferente.

    for(long i = 0; i < QTD_ESCREVER; i++) {
        pthread_create(&escreve[i], 0, thread_escreve, (void *)i);
    }

    for(int i = 0; i < QTD_ESCREVER; i++) {
        pthread_join(escreve[i], NULL);
    }

    // Quando as threads de escrita terminam, as threads de leitura são criadas para ler os arquivos.
    // Cada thread é responsável pela leitura de um arquivo diferente.

    for(long i = 0; i < QTD_LER; i++) {
        pthread_create(&ler[i], 0, thread_le, (void *)i);
    }

    for(int i = 0; i < QTD_LER; i++) {
        pthread_join(ler[i], NULL);
    }

    return 0;
}
