#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define QTD_PROCESSOS 30

int main(void)
{
  int pid_pai = getpid();
  clock_t t;

  t = clock();

  for (int i = 0; i < QTD_PROCESSOS; i++){
    if (getpid() == pid_pai) {
      printf("Novo processo criado!\n");
      fork();
      if(pid_pai != getpid()) {
        sleep(2);
      }
      if(getpid() == pid_pai && i == QTD_PROCESSOS - 1) {
        t = clock() - t;
          
        printf("Tempo de criação dos processos: %ld\n", t);
      }
    }
  }

    return 0;
}