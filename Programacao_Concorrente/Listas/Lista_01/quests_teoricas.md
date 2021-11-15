## Questões:

##### 1) O que é programação concorrente ? Quais são os aspectos a serem observados quanto ao planejamento de sistemas que utilizam processos concorrentes ?

* **O que é programação concorrente:** É um paradigma de programação para a construção de programas de computador que fazem uso da execução simultânea de várias tarefas computacionais interativas, que podem ser implementadas como programas separados ou como um conjunto de threads criadas por um único programa. Essas tarefas podem ser executadas por um único processador, vários processadores em um único equipamento ou processadores distribuídos por uma rede. Programação concorrente é relacionada com programação paralela, mas foca mais na interação entre as tarefas e a coordenação do acesso simultâneo aos recursos computacionais do sistema.

* **Aspectos que devem ser observados no planejamento de sistemas concorrentes:** 
  1. É importante observar se o problema em questão necessita da implementação de concorrência e/ou paralelismo, pois em muitos casos o uso de concorrência pode resultar no aumento significativo da complexidade do sistema, sobre isso alguns aspectos que podem ser observadas são: Existe necessidade de diminuir o tempo de execução do programa ? O problema pode ser dividido em outros pequenos problemas independentes ?
  
  2. É importante entender que é natural que processos de uma aplicação concorrente compartilham recursos. Mas o compartilhamento de recursos traz problemas que podem comprometer a execução da aplicação. Por este motivo, é necessário que os processos de uma aplicação concorrente sejam sincronizados pelo sistema operacional com o objetivo de garantir o processamento correto dos programas. Caso não haja uma gerência no uso concorrente dos recursos compartilhados, inconsistências nos dados podem ocorrer. Nesse contexto, é importante observar as duas propriedades abaixo, pois elas ajudam a garatir a integridade de um programa que utiliza concorrência:
   * **Safety property:** Garante que o programa nunca entra em um estado indesejado, ou seja, um estado em que as variáveis tem valores indesejados.
   * **Liveness property:** Garante que o programa em algum momento entrará no estado desejado.

##### 2) Qual o impacto do advento dos processadores multi-núcleo na implementação e execução de programas que utilizam programação concorrente ? 

* A chegada dos processadores multi-núcleo trouxe novas possíbilidades para os sistemas, como o paralelismo executado localmente. Essas novas possibilidades incrementaram o poder de processamento dos sistemas, pois além de possibilitar que diferentes programas ou diferentes instâncias de um mesmo programa progredissem ao mesmo tempo localmente, não dependendo de um sistema distribuido como os processadores mono-núcleo, otimizou o uso do entrelaçamento, já que agora o sistema pode usar mais de um núcleo para a execução de processos.

##### 3) O que é, em programação concorrente, consistência de memória ?

* Quando estamos lidando com uma região de memória compartilhada por diferentes instâncias de um processo (Threads) podemos cair em diferentes casos de incosistência de memória no qual o resultado final não é o esperado, pois durante o processo de execução do código ocorreu alguma alteração indesejada na região de memória compartilhada. Nesse contexto, consistência de memória seria garantir que nessa região de memória compartilhada, também chamada de sessão crítica, não ocorra nenhuma alteração indesejada, nesse sentido, duas principais propriedades são observadas para garantir a consistência de memória, são elas: 
  * **Safety property:** Garante que o programa nunca entra em um estado indesejado, ou seja, um estado em que as variáveis tem valores indesejados.
  * **Liveness property:** Garante que o programa em algum momento entrará no estado desejado.

##### 4) O que é um processo? Quais são as informações que compreendem o contexto de um processo ? 

*  Um processo pode ser entendido como um programa que está em execução. Além disso, também pode ser definido como o ambiente onde o programa é executado. Este ambiente, além das informações importantes a execução do programa, possui também informações relativas aos recursos que o programa pode utilizar, ou seja, ao contexto do processo.
  
* Os principais recursos utilizados no contexto de um processo são: espaço de endereçamento, uso do processador, área em disco, contador de programa, PID e uma ou mais threads no qual cada uma vai conter a informação sobre seu registrador, estado e pilha.