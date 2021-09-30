#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define QTD_THREADS 26

void *func_thread(void *param) {
    // Traduzindo indice para seu algarismo correspondente na tabela asc
    long id = (long) param + 65;
    char aux[5];

    // Espaço que cada thread vai utilizar para guarda sua parte da string
    char *aux2 = (char *) malloc(88556 * sizeof(char));

    // Identificando qual valor será iniciado a parte do identificador da thread
    for(int i = 0; i < QTD_THREADS; i++) {
        if(id == ('A' + i)) {
            aux[0] = 'A' + i;
            break;
        }
    }

    // Preenchendo cada parte da threand a partir da concatenação da variável aux
    for(int i = 0; i < QTD_THREADS; i++) {
        aux[1] = 'A' + i;
        for(int j = 0; j < QTD_THREADS; j++) {
            aux[2] = 'A' + j;
            for(int k = 0; k < QTD_THREADS; k++) {
                aux[3] = 'A' + k;
                aux[4] = ',';

                strcat(aux2, aux);
            }
            strcat(aux2, "\n");
        }
    }

    pthread_exit((void*) aux2);

}

int main(void) {
    pthread_t threads[QTD_THREADS];
    char *results;

    // criando threads
    for(long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, func_thread, (void *)i);
    }

    FILE *arq;
    arq = fopen("result.txt", "wt");

    // Esperando threads terminarem e preenchendo arquivos
    if(arq == NULL) {
            printf("Erro!\n");
    }else {
        for (int i = 0; i < QTD_THREADS; i++) {
            pthread_join(threads[i], (void*)&results);

            fprintf(arq,"%s",results);
            free(results);
        }
    }

    fclose(arq);

    return 0;
}