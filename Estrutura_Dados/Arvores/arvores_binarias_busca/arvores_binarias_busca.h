#ifndef _ARVORESBINARIASBUSCA_H_
#define _ARVORESBINARIASBUSCA_H_

typedef struct arv Arv;
typedef struct arvno ArvNo;
Arv* arv_cria();
ArvNo* arv_busca(Arv* arv, int valor);
void arv_insere(Arv* arv, int valor);
void arv_remove(Arv* arv, int valor);
void arv_libera(Arv* arv);

#endif