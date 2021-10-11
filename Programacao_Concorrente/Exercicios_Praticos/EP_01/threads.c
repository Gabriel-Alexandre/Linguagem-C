#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define TAM_THREAD 6

char stringR[10];
int soma = 0;

void *func_thread(void *param) {
    // Traduzindo indice para seu algarismo correspondente na tabela asc
    long id = (long) param + 48;

    char aux[6];
    aux[0] = id;

    char linha[10];

    strcat(aux, ".txt");

    // Abre o arquivo de acordo com o id de sua thread correspondente
    FILE *arq;
    arq = fopen(aux, "rt");

    // Lê o arquivo enquando ele tem linha
    while(fgets(linha, 10, arq)) {
        linha[strlen(linha)-1] = '\0';
        
        // Se a linha tiver a string digitada, soma na variavel global
        if(!strcmp(linha, stringR)) {
            __sync_fetch_and_add(&soma, 1);
        }
    }

    fclose(arq);
}

int main() {
    pthread_t threads[TAM_THREAD];

    printf("Digite a string desejada: ");
    fgets(stringR, 10, stdin);
    stringR[strlen(stringR)-1] = '\0';

    // Cria threads
    for(long i = 0; i < TAM_THREAD; i++) {
        pthread_create(&threads[i], NULL, func_thread, (void *)i);
    }

    // Espera threads as finalizarem
    for(int i = 0; i < TAM_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Soma das ocorrencias de [%s] é: %d\n", stringR, soma);

    return 0;
}



/* 

* Processo: É o programa em execução e o ambiente onde o programa vai ser executado. Contém informações 
sobre a execução do programa e sobre os recursos que o programa pode utilizar como espaço de endereçamento, 
uso do processador, área em disco, etc.

* Thread: É uma "Linha" de execução dentro de um processo, no qual cada thread tem o seu próprio estado de processador 
e a sua própria pilha. Além disso, todas as threads dentro de um mesmo processo ocupam a mesma região de memória, o que 
facilita a troca de informações.


Do ponto de vista de execução as threads são muito menos custosas que os processos, justamente pelo fato de serem uma
instância deste, o que as torna melhores no quisito de desempenho, porém isso não as torna melhores que os processos,
pois em aplicações onde o isolamento das instâncias é muito importante, os processos se tornam melhores candidatos, 
justamente pelo fato de terem um contexto independente no qual podem se isolar do restante do sistema. Assim nos
códigos de threads e processos, o código que executa as threads tende a executar mais rápido por que apresentam um
menor contexto.

*/