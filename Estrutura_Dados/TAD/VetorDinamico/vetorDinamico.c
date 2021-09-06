#ifndef _VETORDINAMICO_C_
#define _VETORDINAMICO_C_
#include <stdio.h>
#include <stdlib.h>
#include "vetorDinamico.h"

struct vetorDinamico {
    int n;
    int dim;
    float *v;
};

VetorDinamico *criaVetor(int dim) {

    VetorDinamico *vetor =  (VetorDinamico *) malloc(sizeof(VetorDinamico));
    
    vetor->v = (float *) malloc(dim * sizeof(float));

    vetor->n = 0;
    vetor->dim = dim;

    return vetor;
}

int insere_vetor(VetorDinamico *vetor, float v) {
    if(vetor) {
        if(vetor->n == vetor->dim) {
            if(realloc(vetor->v, vetor->dim+vetor->dim)) {
                vetor->dim = vetor->dim+vetor->dim;

                vetor->v[vetor->n] = v;
                vetor->n++;
        
                return 1;
            }
            return 0;
        }

        vetor->v[vetor->n] = v;
        vetor->n++;

        return 1;
    }
    
    return 0;
}

int acessa_vetor(VetorDinamico *vetor, int i, float *v) {
    if(vetor) {
        *v = vetor->v[i];

        return 1;
    }

    return 0;
}

int tamanho_vetor(VetorDinamico *vetor) {
    return vetor->dim;
}

void libera_vetor(VetorDinamico *vetor) {
    free(vetor);
}

#endif