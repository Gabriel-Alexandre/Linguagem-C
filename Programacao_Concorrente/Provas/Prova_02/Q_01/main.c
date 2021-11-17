#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define QTD_THREADS 5

// Responsável por garantir a exclusão mútua
pthread_mutex_t mutex_lock_control = PTHREAD_MUTEX_INITIALIZER;
// Responsável por garantir o sincronismo condicional
pthread_barrier_t controle_barreira;

char string[QTD_THREADS];
int exec = 1;
int liberar_letras = 0;

void* gera_letra(void *p) {
    long index = (long)p;

    while(exec) {
        // Gera letra maiúscula aleatória
        char letra = 'A' + rand() % 26;
        pthread_mutex_lock(&mutex_lock_control); // Protocolo de entrada
        string[index] = letra;      // Seção crítica
        __sync_fetch_and_add(&liberar_letras, 1); 
        pthread_mutex_unlock(&mutex_lock_control);  // Protocolo de saída

        // Ponto de embarreiramento
        // - A barreira só será liberada quando todas as 5 threads + thread main terminarem de executar
        // suas instruções.
        int wait_ret_total = pthread_barrier_wait(&controle_barreira);

        if ((wait_ret_total != 0) && (wait_ret_total != PTHREAD_BARRIER_SERIAL_THREAD)) {
            printf("BARRIER ERROR!\n");
            exit(0);
        }
    }
}

int main() {
    time_t t;

    pthread_t thread[QTD_THREADS];

    srand((unsigned)time(&t));

    int cont_palindromo = 0;

    int init_bar_ret = pthread_barrier_init(&controle_barreira, NULL, QTD_THREADS+1);

    for (long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&thread[i], 0, gera_letra, (void *)i);
    }

    // Condição de parada -> Quando 4 palíndromo forem gerados
    while(cont_palindromo < 4) {
        // Identifica se as 5 letras foram geradas
        if(liberar_letras > 0 && liberar_letras == 5) {
            pthread_mutex_lock(&mutex_lock_control); // Protocolo de entrada

            char aux[QTD_THREADS];
            int j = 0;

            for(int i = QTD_THREADS-1; i >= 0; i--) {
                aux[j] = string[i];
                j++;
            }

            if(!strcmp(aux, string)) {
                cont_palindromo++;
                printf("[%s] string gerada - É Palíndromo - (%d)\n", string, cont_palindromo);
                sleep(3);
            } else {
                printf("[%s] string gerada - Não é Palíndromo - (%d)\n", string, cont_palindromo);
            }

            liberar_letras = 0; // Reseta o número de letras
            pthread_mutex_unlock(&mutex_lock_control); // Protocolo de saída

            // Sinaliza que a thread principal terminou sua execução
            pthread_barrier_wait(&controle_barreira);
        }
    }

    exec = 0;

    printf("Finalizado\n");

    return 0;
}