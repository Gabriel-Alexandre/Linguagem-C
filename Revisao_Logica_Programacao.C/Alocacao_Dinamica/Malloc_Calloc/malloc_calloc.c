#include <stdio.h>
#include <stdlib.h>
// Lib que possibilita usar as funções de alocação dinâmica

int main(void) {
  int *p = (int*) malloc(sizeof(int));
  // malloc (bytes)
  // Zera a memoria alocada
  int *q = (int*) malloc(30*sizeof(int));
  // Zera a memoria alocada
  int *r = (int*) calloc(30, sizeof(int));
  // calloc(num, bytes)
  // Zera a memoria alocada

  // printf("%d\n", *p);

  for(int i = 0; i < 30; i++) {
    r[i] = i+1;
  }

  for(int i = 0; i < 30; i++) {
    printf("%d\n", r[i]); 
  }
  
  // Sempre liberar a memoria alocada dinâmicamente, caso eu esqueça de liberar
  // A memoria vai ser perdida.
  free(p);
  free(q);
  free(r);
}