#include <stdio.h>

// Arvores AVL

// Definição da estrutura
typedef struct arv Arv;
typedef struct arvno ArvNo;

struct arv {
    ArvNo* raiz;
};

struct arvno {
    int info;
    int alt; // altura da sub-árvore
    ArvNo* esq;
    ArvNo* dir;
};

// --------------------------------------------------------------------


static int insereAVL(ArvNo* raiz, int valor) {
    int res;
    // Se for o nó raiz ou um nó folha, cria um nó com o valor recebido e retorna 1
    if(raiz == NULL) {
        ArvNo *novo = (ArvNo*) malloc(sizeof(ArvNo));

        if(novo == NULL) return 0;
        
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL; 
        novo->dir = NULL;
        raiz = novo;

        return 1;
    } 
    ArvNo *atual = raiz;
    // Se o valor recebido for menor que a raiz, inserir a esquerda
    if(valor < atual->info) {
        // Se a resposta "res" da inserção for 1, verificar balanceamento
        if((res = insereAVL(atual->esq, valor)) == 1) {
            // Se o fator de balanceamento for maior que 2, balancear nó
            if(fatorBalanceamento_no(atual) >= 2) {
                // Se o valor é maior que o valor da sub-árvore a esquerda, aplicar LL
                if(valor < raiz->esq->info) {
                    RotacaoLL(raiz);
                // Se não, aplicar LR
                } else {
                    RotacaoLR(raiz);
                }
            }
        } 
    } else {
        // Se o valor recebido for maior que a raiz, inserir a direita
        if(valor > atual->info) {
            // Se a resposta "res" da inserção for 1, verificar balanceamento
            if((res = insereAVL(atual->esq, valor)) == 1) {
            // Se o fator de balanceamento for maior que 2, balancear nó
                if(fatorBalanceamento_no(atual) >= 2) {
                    // Se o valor é maior que o valor da sub-árvore a direita, aplicar RR
                    if(valor > raiz->dir->info) {
                        RotacaoRR(raiz);
                    // Se não, aplicar RL
                    } else {
                        RotacaoRL(raiz);
                    }
                }
            }
        } else {
            // Se o valor for duplicado não inserir
            return 0;
        }
    }

    // Recalcular altura do nó atual
    atual->alt = maior(atual->esq->alt, atual->dir->alt) + 1;

    return res;
}

int arv_insereAVL(Arv* arv, int valor) {
    if(arv == NULL) return -1;
    
    int res = insereAVL(arv->raiz, valor); // Verifica se a inserção deu certo

    return res;
}