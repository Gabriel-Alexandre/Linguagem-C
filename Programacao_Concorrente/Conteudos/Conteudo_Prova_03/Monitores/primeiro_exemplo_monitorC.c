#include <stdio.h>
#include <pthread.h>

typedef struct {
    int id_cliente;
    double saldo;
    pthread_mutex_t mutex;
} conta_corrente;

float get_saldo(conta_corrente *cc) {
    return cc->saldo;
}

void altera_saldo(conta_corrente *cc, float valor) {
    pthread_mutex_lock(&cc->mutex);
    cc->saldo += valor;
    pthread_mutex_unlock(&cc->mutex);
}

conta_corrente cc1;

void *operacoes1(void *p) {
    unsigned int counter = 0;
    while(counter < 100) {
        altera_saldo(&cc1, 100);
        printf("[c]%f\n", cc1.saldo);
        counter++;
    }
}

void *operacoes2(void *p) {
    unsigned int counter = 0;
    while(counter < 99) {
        altera_saldo(&cc1, -100);
        printf("[c]%f\n", cc1.saldo);
        counter++;
    }
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, operacoes1, NULL);
    pthread_create(&thread2, NULL, operacoes2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Saldo final: %.2f\n", cc1.saldo);
}