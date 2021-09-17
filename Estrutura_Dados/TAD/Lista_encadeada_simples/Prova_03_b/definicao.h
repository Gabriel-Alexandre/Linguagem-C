#ifndef _LISTA_ENCADEADA_H_
#define _LISTA_ENCADEADA_H_

typedef int Elemento; 

typedef struct no No;

void criar_lista(No **lista);
No *ll_create_no(int info);
int ll_insert_first(No **lhead, int info);
int ll_insert_last(No **lhead, int info);
int ll_insert_half(No **lhead, int info, int i);

#endif