#include <stdio.h>
#include <stdlib.h>
#include "matrizD.h"
#ifndef _MATRIZD_C_
#define _MATRIZD_C_

struct matrizD {
    int l;
    int c;
    float **v;
};

MatrizD *criaMatrizD(int l, int c) {

    MatrizD *m = (MatrizD *) malloc(sizeof(MatrizD));

    m->l = l;
    m->c = c;
    
    m->v = malloc(l * sizeof(float*));

    for(int i = 0; i < l; i++) {
        m->v[i] = (float*) malloc(c * sizeof(float));
    }

    return m;
}

void liberaMatrizD(MatrizD *m) {
    if(m) {
        for(int i = 0; i < m->l; i++) {
        free(m->v[i]);
        }

        free(m->v);
    }
}

int acessaMatrizD(MatrizD *m, int i, int j, float *v) {

    if(m) {
        *v = m->v[i][j];

        return 1;
    }

    return 0;
}

int atribuiMatrizD(MatrizD *m, int i, int j, float v) {

    if(m) {
        m->v[i][j] = v;

        return 1;
    }

    return 0;
}

int nlinhas(MatrizD *m) {
    return m->l;
}

int ncolunas(MatrizD *m) {
    return m->c;
}

#endif