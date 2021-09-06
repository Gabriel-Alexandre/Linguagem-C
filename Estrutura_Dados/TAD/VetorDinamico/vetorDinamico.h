#ifndef _VETORDINAMICO_H_
#define _VETORDINAMICO_H_

typedef struct vetorDinamico VetorDinamico;
VetorDinamico *criaVetor(int dim);
int insere_vetor(VetorDinamico *vetor, float v);
// Insere na próxima posição vazia (Se ainda não estiver alocado, ele realoca o vetor)
int tamanho_vetor(VetorDinamico *vetor);
int acessa_vetor(VetorDinamico *vetor, int i, float *v);
void libera_vetor(VetorDinamico *vetor);

#endif