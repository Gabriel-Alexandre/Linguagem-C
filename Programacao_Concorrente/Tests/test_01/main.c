#include <stdio.h>
#include <unistd.h>

// ps au (Verificar os processos)
// top (Vericar os processos)
// & (Executa em background)
// fg (Traz o programa que está em background para forenground)
// bg (Deixa o programa em espera em background, para que em algum momento ele possa voltar a executar)
// crtl c (Para o programa e volta ao terminal)
// crtl z (Suspende o programa e volta para o terminal)
// kill (PID) (Finaliza o programa de forma forçada)

// Falta entender um pouco melhor sobre os comandos:

/*
1- (| - Pipe)
2- (> - operador de indireção)

>> Buscar entender melhor sobre esses comandos no momento mais propício.
*/

int main() {

    while(1) {
        printf("a\n");
        sleep(5);
    }

    return 0;
}