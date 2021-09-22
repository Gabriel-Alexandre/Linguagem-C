#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // argc -> argument cout (Número de elementos do array)
    // argv -> argument value (Array de strings)

    for (int i = 0; i < argc; i++) {
        printf("[MOSTRA] [%d] %s\n", i, argv[i]);
    }

    sleep(2);

    return 0;
}