#ifndef _ARVORESBINARIAS_H_
#define _ARVORESBINARIAS_H_

typedef struct arv Arv;
typedef struct arvno ArvNo;
Arv* arv_cria(ArvNo* r);
ArvNo* arv_criano(char c, ArvNo* esq, ArvNo* dir);
void arv_libera(Arv* arv);
void arv_imprime(Arv* arv);
int arv_pertence(Arv* arv, char c);
int arv_altura(Arv* arv);

#endif