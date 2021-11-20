#ifndef _ARVORESBINARIAS_H_
#define _ARVORESBINARIAS_H_

typedef struct no* No;
No* cria_arv();
int inserirNo_arv(int n, No* raiz, No* esq, No* dir);
int pertence_arv(int n, No* raiz);
void libera_arv(No* raiz);
int estaVazia_arv(No* raiz);
int altura_arv(No* raiz);
int totalNo_arv(No* raiz);
void preOrdem_arv(No* raiz);
void posOrdem_arv(No* raiz);
void emOrdem_arv(No* raiz);

#endif