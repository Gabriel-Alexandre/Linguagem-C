#ifndef _PONTO_C_
#define _PONTO_C_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

// Implementação das funções
// Seguir o modelo de encapsulamento

struct ponto {
    float p[2];
};

Ponto *cria_ponto(float x, float y) {

    Ponto *p = (Ponto *) malloc(sizeof(Ponto));

    if(p) {
        p->p[0] = x;
        p->p[1] = y;
    }

    return p;
}

void libera_ponto(Ponto *p) {
    free(p);
}

int pega_ponto(Ponto *p, float *x, float *y) {
    
    if(p) {
        *x = p->p[0];
        *y = p->p[1];

        return 1;
    }

    return 0;
}

int seta_ponto(Ponto *p, float x, float y) {

    if(p) {
        p->p[0] = x;
        p->p[1] = y;

        return 1;
    }

    return 0;
}

float calcula_distancia(Ponto *p, Ponto *q) {

    if(p && q) {
        return (sqrt(pow(p->p[0]-q->p[0],2)+pow(p->p[1]-q->p[1],2)));
    }

    return -1.0f;
}

void mostra(Ponto *p) {
    printf("(%.2f, %.2f)\n", p->p[0], p->p[1]);
}

#endif