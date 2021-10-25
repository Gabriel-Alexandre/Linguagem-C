#include <stdio.h>

// Para entender esse arquivo é importante entender a diferença entre passar o valor por valor e por referência.
// Como estou lidando com endereços de memória eu estou lidando com a passagem por referência.

// Quando eu coloco array[] ele vai espera não um array, mas o endereço de memoria do primeiro elemento.

int funcArray(int array[], int i) {

    for(int j = 0; j < i; j++) {
        array[j] = j;
    }

    return 0;
}


// int funcArray(const int array[], int i) {

//     for(int j = 0; j < i; j++) {
//         printf("%d\n", array[1]);
//     }

//     return 0;
// }

// *int funcArray() {
//     static int naoZumbi[5];

//     for(int j = 0; j < 5; j++) {
//         naoZumbi[j] = j;
//     }

//     return naoZumbi;
// }


// O indice também é passado para evitar acesso de elementos inexistentes.
// O const é utilizado para evitar que aconteça alterações nos elementos do array.
//  - Dessa maneira, eu só posso acessalos, e não alteralos.
//  - Dessa maneira, se eu quiser fazer alterações é só não colocar o const.
// Da mesma forma que a função não pode receber um array como parâmetro, ela não pode retorna um array.
//  - Assim sendo, o que é passado e retornado é o endereço de memoria da primeira ocorrência.
//      - Dessa maneira, é importante tomar cuidado com o retorno de arrays zumbis, que acontece quando retornamos um
//      endereço de memoria que não está mais alocado, pois é de duração automática. Assim sendo, se for retorna um arrays
//      devo me certifica que ele é de duração fixa. (Variável global ou variável com static).

int main() {
    int array[5] = {0, 0, 0, 0, 0};

    funcArray(array, 5);
    // É o mesmo que est
    // funcArray(&array[0], 5)

    // Uma função não pode passar um array como parâmetro, então ela passa um endereço de memoria.
    // O próprio array é passado como parâmetro já que ele representa o endereço do array.
    

    // Se eu quiser utilizar um array em uma função, é só ler esse arquivo e seguir a sintaxe.

    printf("%d\n", array[2]);

    return 0;
}