#include <stdio.h>

int main (void)

{
  int segundos;
  float minutos, horas;

  printf("Digite o tempo em segundos: ");
  scanf("%d", &segundos);

  minutos = segundos / 60;
  horas = segundos / 3600;

  printf("Para %d segundos temos: %.1f minutos e %.1f horas", segundos, minutos, horas);

  return 0;
}
