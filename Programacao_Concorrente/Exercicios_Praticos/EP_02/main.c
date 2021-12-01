#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N_PASSAGEIROS 20
#define QTD_MAX_CARRO 5
#define QTD_VOLTAS 5

pthread_mutex_t volta = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t number_inc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t entrar_carro, da_volta, sair_carro;

int pessoas_parque = 1;
int fecharParque = 0;
int voltas = 0;
int n_passageiros = 0;
int n_termino_passageiros = 0;

int number = 1;
int next = 1;
int turn[N_PASSAGEIROS];

void *passageiros_func(void *p) {
    long index = (long)p;

    while(!fecharParque) {
        // Cada thread recebe seu ticket
        pthread_mutex_lock(&number_inc_mutex);
        // - A cada QTD_MAX_CARRO threads o ticket muda
        // - Cada ticket equivale QTD_MAX_CARRO entradas
        if(__sync_fetch_and_add(&n_passageiros, 1) == QTD_MAX_CARRO) {
            n_passageiros = 1;
            number++;
        }
        turn[index] = number;
        pthread_mutex_unlock(&number_inc_mutex);

        // Só passam as threads que contém o ticket da vez
        // Teste: printf("turn[%ld] =  %d, next = %d\n", index, number, next);
        while(turn[index] != next) {
            usleep(100);
        }      

        // Executa entrada, percurso e saída do carrinho
        pthread_barrier_wait(&entrar_carro);
        printf("Passageiro [%ld] entrou no carro\n", index);
        pthread_barrier_wait(&da_volta);
        printf("Passageiro [%ld] saiu do carro\n", index);
        pthread_barrier_wait(&sair_carro);
        sleep(1 + rand() %6);

        // Atualiza ticket
        pthread_mutex_lock(&number_inc_mutex);
        if(__sync_fetch_and_add(&n_termino_passageiros, 1) == (QTD_MAX_CARRO - 1)) {
            n_termino_passageiros = 0;
            __sync_fetch_and_add(&next, 1);
            usleep(10000);
        }
        pthread_mutex_unlock(&number_inc_mutex);
    }
}

void *carro_func(void *p) {
    while(pessoas_parque) {
        // Executa entrada, percurso e saída do carrinho
        pthread_barrier_wait(&entrar_carro);
        pthread_mutex_lock(&volta);
        usleep(10000);
        printf("Carrinho dando uma volta\n");
        pthread_mutex_unlock(&volta);
        pthread_barrier_wait(&da_volta);
        pthread_barrier_wait(&sair_carro);
        __sync_fetch_and_add(&voltas, 1);
        printf("Voltas = %d\n", voltas);
    }
}

int main() {
    time_t t;
    srand((unsigned)time(&t));

    pthread_t passageiros[N_PASSAGEIROS];
    pthread_t carro;

    pthread_barrier_init(&entrar_carro, NULL, QTD_MAX_CARRO+1);
    pthread_barrier_init(&sair_carro, NULL, QTD_MAX_CARRO+1);
    pthread_barrier_init(&da_volta, NULL, QTD_MAX_CARRO+1);

    for (int i = 0; i < N_PASSAGEIROS; i++)
        turn[i] = 0;

    pthread_create(&carro, 0, carro_func, NULL);

    for (long i = 0; i < N_PASSAGEIROS; i++) {
        pthread_create(&passageiros[i], 0, passageiros_func, (void *)i);
    }

    // Condição de parada
    while(voltas < QTD_VOLTAS) {
        usleep(100);
    }
    fecharParque = 1;
    pessoas_parque = 0;

    printf("Parque fechou!\n");

    return 0;
}