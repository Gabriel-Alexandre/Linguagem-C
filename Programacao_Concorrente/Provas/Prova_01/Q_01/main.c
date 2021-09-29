#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define VALOR_MAX 100





// Questão imcompleta!






typedef struct {
    int index;
    int salto;
    int soma;
    int distancia
} t_lebre;

void *func_thread(void *param) {
    t_lebre *id = (t_lebre*)param;

    if(id->soma > id->distancia) {
        printf("Lebre [%d] ganhou!\n", id->index);
        pthread_exit((void*) 1);
    }else {

        printf("Lebre [%d] saltou [%d]: (Total: %d)\n", id->index, id->salto, id->soma);
        id->soma += id->salto;
        pthread_exit((void*) 0);
    }
}

int main(int argc, char *argv[]) {
    

    char *op = argv[0];
    char *instanciaarg = argv[1];
    char *distanciaarg = argv[2];

    int instancia = atoi(instanciaarg);
    int distancia = atoi(distanciaarg);

    if(op == '-t') {
        // Threads

        pthread_t threads[instancia];
        int results[instancia];
        t_lebre lebre[instancia];
        int soma = 0;

        time_t t;

        srand((unsigned)time(&t));

        for(int i = 0; instancia; i++) {
            lebre[i].index = i + 1;
            lebre[i].salto = 1+ rand() % VALOR_MAX;
            lebre[i].soma = 0;
            lebre[i].distancia = distancia;
        }

        for(long i = 0; i < instancia; i++) { 
            pthread_create(&threads[i], NULL, func_thread, (void *)lebre); 
        }

    } else {
        // Processos

    }

    return 0;
}