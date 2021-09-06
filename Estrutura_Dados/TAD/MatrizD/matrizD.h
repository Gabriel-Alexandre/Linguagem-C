#ifndef _MATRIZD_H_
#define _MATRIZD_H_

typedef struct matrizD MatrizD;
MatrizD *criaMatrizD(int l, int c);
void liberaMatrizD(MatrizD *m);
int acessaMatrizD(MatrizD *m, int i, int j, float *v);
int atribuiMatrizD(MatrizD *m, int i, int j, float v);
int nlinhas(MatrizD *m);
int ncolunas(MatrizD *m);

#endif