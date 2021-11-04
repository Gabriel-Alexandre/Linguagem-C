#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int pid_pai = getpid();
    int qnt;

    printf("Pai PID: %d\n", getpid());

    printf("Quantidade de clones:  ");
    scanf("%d", &qnt);

    for (int i = 0; i < qnt; i++){
      if (getpid() == pid_pai){
        printf("Clone \n");
        fork();
      }
    }

    sleep(2);
    printf("Finalizando processo de PID: %d\n", getpid());
}