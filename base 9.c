#include <stdio.h>

int main (void)

{
   int x,y,z;
   int soma,produto,mediaA;

   printf("Digite o primeiro valor: ");
   scanf("%d", &x);
   printf("Digite o segundo valor: ");
   scanf("%d", &y);
   printf("Digite o terceiro valor: ");
   scanf("%d", &z);

   soma = x + y + z;
   produto = x * y * z;
   mediaA = (x + y + z) / 3;

   printf("a soma dos tres valores eh: %.1d\n", soma);
   printf("o produto dos tres valores eh: %.1d\n", produto);
   printf("a media aritimetica dos tres valores eh: %.1d\n", mediaA);

  return 0;
}
