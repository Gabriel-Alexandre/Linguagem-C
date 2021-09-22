#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // API de thread dos sistemas posix

int var_global;

// A função precisa receber um void* e retornar um void*
void *funcao_thread(void *param)
{
    int var_local;
    var_local = 99;
    printf("Dentro da funcao_thread\nvar_global = %d\n", var_global);
    printf("var_local = %d\n", var_local);
    sleep(5);
    var_global++;
    var_local++;
    printf("Saindo da funcao_thread\nvar_global = %d\nvar_local = %d\n",
           var_global, var_local);
}

int main(void)
{
    var_global = 1000;
    pthread_t thread1, thread2;

    printf("Dentro da funcao main()\n");
    printf("Vou criar duas threads!\n");

    // Os parâmetros vão ser melhor explicados depois
    pthread_create(&thread1, NULL, funcao_thread, NULL);
    pthread_create(&thread2, NULL, funcao_thread, NULL);

    sleep(10);

    printf("Fechando funcao main\nvar_global = %d\n", var_global);

    return 0;
}