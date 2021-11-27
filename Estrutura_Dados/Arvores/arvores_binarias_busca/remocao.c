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

// ----------------------------------------------------------------------------------------------------------

static int removerAVL(ArvNo* raiz, int valor) {
    if(raiz == NULL) return 0; // Valor não existe

    int res;
    // Se o valor recebido for menor que a raiz, remover a esquerda
    if(valor < raiz->info) {
        // Se a resposta "res" da inserção for 1, verificar balanceamento
        if((res = removerAVL(raiz->esq, valor)) == 1) {
            // Se o fator de balanceamento for maior que 2, balancear nó
            if(fatorBalanceamento_no(raiz >= 2)) {
                // Verificar se a altura da sub-árvore a esquerda da sub-árvore a direita da raiz
                //  é menor ou igual que a altura da sub-árvore a direita da sub-árvore a direita 
                // da raiz, se sim aplicar RR
                if(raiz->dir->esq->alt <= raiz->dir->dir->alt) {
                    RotacaoRR(raiz);
                } else {
                    // Se não aplica RL
                    RotacaoRL(raiz);
                }
            }
        }
    // Se o valor recebido for menor que a raiz, remover a direita
    } if(valor > raiz->info) {
        if((res = removerAVL(raiz->esq, valor)) == 1) {
            // Se o fator de balanceamento for maior que 2, balancear nó
            if(fatorBalanceamento_no(raiz >= 2)) {
                // Verificar se a altura da sub-árvore a direita da sub-árvore a esquerda da raiz
                //  é menor ou igual que a altura da sub-árvore a esquerda da sub-árvore a esquerda 
                // da raiz, se sim aplicar LL
                if(raiz->esq->dir->alt <= raiz->esq->esq->alt) {
                    RotacaoLL(raiz);
                } else {
                    // Se não aplica LR
                    RotacaoLR(raiz);
                }
            }
        } 
    // Se o valor recebido for igual que a raiz, remover nó
    } if(raiz->info == valor) {
        // Se a raiz tem 1 ou nenhum um filho
        if(raiz->esq == NULL || raiz->esq->dir == NULL) {
            ArvNo *oldNo = raiz;
            // Identifica qual é o filho
            if(raiz->esq != NULL)
                raiz = raiz->esq;
            else
                raiz = raiz->dir;
            // Libera raiz
            free(oldNo);
        // Se a raiz tem 2 filhos
        } else {
            // Procurar sucessor, que é a sub-árvore mais a esquerda da sub-árvore a direita da raiz
            ArvNo *temp = procuraMenor(raiz->dir);
            raiz->info = temp->info;
            removerAVL(raiz->dir, raiz->info);
            // Se o fator de balanceamento for maior que 2, balancear nó
            if(fatorBalanceamento_no(raiz) >= 2) {
                // Verificar se a altura da sub-árvore a direita da sub-árvore a esquerda da raiz
                //  é menor ou igual que a altura da sub-árvore a esquerda da sub-árvore a esquerda 
                // da raiz, se sim aplicar LL
                if(raiz->esq->dir->alt <= raiz->esq->esq->alt) {
                    RotacaoLL(raiz);
                } else {
                    // Se não aplica LR
                    RotacaoLR(raiz);
                }
            }
        }
        return 1;
    }
    return res;
}

int arv_removeAVL(Arv* arv, int valor) {
    if(arv == NULL) return -1;

    int res = removerAVL(arv->raiz, valor); // Verifica se a remoção deu certo

    return res;
}



// Procura pela sub-árvore mais a esquerda
ArvNo *procuraMenor(ArvNo *atual) {
    ArvNo *no1 = atual;
    ArvNo *no2 = atual->esq;

    while(no2 != NULL) {
        no1 = no2;
        no2 = no2->esq;
    }

    return no1; 
}