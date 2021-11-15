#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define TAM_THREAD 10

double varGlobal;

void *func_thread(void *param) {
    long id = (long) param;

    if(id % 2 == 0) {
        // Par
        for(int i = 0; i < 10; i++) {
            varGlobal++;
        }

    }else {
        // Impar
        for(int i = 0; i < 10; i++) {
            varGlobal--;
        }  
    }

    printf("id thread = %ld, novo valor varGlobal = %.2lf\n", id, varGlobal);
}

int main() {
    pthread_t threads[TAM_THREAD];
    time_t t;
    int tempo;

    varGlobal = 0;

    srand((unsigned)time(&t));

    for(long i = 0; i < TAM_THREAD; i++) {
        tempo = 1 + rand()%4;
        sleep(tempo);  
        pthread_create(&threads[i], NULL, func_thread, (void *)i);
        printf("Tempo: %d\n", tempo); 
    }

    for (int i = 0; i < TAM_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nvarGlobal [FINAL]: %.2lf\n", varGlobal);

    return 0;
}

/* Concorrência: 

    * Conjunto de tarefas sendo executadas de forma intercalada em um mesmo intervalo de tempo. 
    É uma forma de lidar com muitas coisas ao mesmo tempo e está ligado a forma de se estruturar tarefas.

*/

/* Elementos do sistema operacional que atuam durante a execução do programa:

    * Processo: É o programa em execução e o ambiente onde o programa vai ser executado. 
    Contém informações sobre a execução do programa e sobre os recursos que o programa pode utilizar como 
    espaço de endereçamento, uso do processador, área em disco, etc.

    * Thread: É uma "Linha" de execução dentro de um processo, no qual cada thread tem o seu próprio 
    estado de processador e a sua própria pilha. Além disso, todas as threads dentro de um mesmo processo 
    ocupam a mesma região de memória, o que facilita a troca de informações.

    * Escalonador: É o responsável por decidir a ordem de execução dos processos levando em conta critérios 
    como tempo de execução, tempo de espera, tempo de resposta, eficiência, justiça, etc.

    >> No código acima existe apenas um processo, e nesse processo são criadas 10 threads no cada uma incrementa ou
    decrementa 10 unidades a variável global (Região de memória compartilhada) e são justamente essas threads que
    tornam o programa concorrente, pois uma thread não espera outra thread finalizar para está pronta para execução, 
    o que acontece é: A partir do momento que as threads são criadas, elas passam a competir entre si pelo acesso
    ao escalonador, e da maneira como o código foi implementado uma thread que foi criada depois pode ser finalizada 
    antes de uma thread anterior a ela, já que o tempo é aleatório entre 1 e 4 segundos.
*/

/* 
    Consistência de memória: O código implementado acima apresenta uma certa inconsistência de memória, pois a região de
    memória compartilhada é incrementada com mais de uma instrução, apesar de ser um única instrução na linguagem C, 
    em um nível mais baixo de linguagem de programação, a instrução é dividida em outras instruções menores, e esse 
    procedimento pode causar perca de valores durante a execução do programa, pois como as threads criadas executam 
    de maneira concorrente e o escalonador não escolhe de maneira sequêncial as threads executadas, então durante as
    execuções da threads pode ocorrer perdas de valores que deveriam ter sido somados ou subtraídos.
*/