#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int *p;

    p = array;

    // p[0] = 10;
    // É o mesmo que 
    // *p = 10;
    // Pois, *(p + 0) = 10;

    // array[0] = 10;
    // É o mesmo que
    // *array = 10;
    // Pois, *(array + 0) = 10;

    // p++; -> Posso fazer 
    // array++; -> Não posso fazer

    // É importante saber trabalhar com essa relação, pois me permite criar funções mais complexas.

/* 
    Em C, se o array está sozinho (sem indicação de qual indice ele está se referindo) ele aponta para o endereço
    de memoria do primeiro indice, ou seja:

    p = array; 
    é igual a
    p = &array[0];

    A linguagem me permite relacionar ponteiros e arrays de maneiras interessantes, como no exemplo abaixo:

    array[1]
    é igual a 
    *(array + 1)
    ou
    *(p + 1)
    ou
    p[1]
    >> Isso acontece porque eu criei uma ligação entre o meu ponteiro é o array.
    >> É como se o ponteiro se tornasse equivalente ao nome array.
    >> Esse assunto é importante, pois me permite lidar com aritimetica de ponteiros no array.
    >> Esse assunto é importante, pois me permita fazer copia de arrays utilizando sua referência. (Lembrar que o ponteiro
    vai apontar para o endereço de memória recebido, assim sendo, se eu coloca &array[2] ele não vai apontar para o primeiro
    indice).
*/

    // -> Além dos conceitos, é só saber a sintaxe e aplicar.

    printf("%d\n", array[2]);



    return 0;
}