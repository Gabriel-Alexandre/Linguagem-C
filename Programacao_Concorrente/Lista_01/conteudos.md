## Conteúdos:

### Programação concorrente e paralela:

#### O que é concorrencia:

* Conjunto de tarefas sendo executadas de forma intercalada em um mesmo intervalo de tempo. É uma forma de lidar com muitas coisas ao mesmo tempo e está ligado a forma de se estruturar tarefas.

#### O que é programação concorrente:

* É um paradigma de programação para a construção de programas de computador que fazem uso da execução simultânea de várias tarefas computacionais interativas, que podem ser implementadas como programas separados ou como um conjunto de threads criadas por um único programa. Essas tarefas podem ser executadas por um único processador, vários processadores em um único equipamento ou processadores distribuídos por uma rede. Programação concorrente é relacionada com programação paralela, mas foca mais na interação entre as tarefas e a coordenação do acesso simultâneo aos recursos computacionais do sistema.

#### O que é paralelismo:

* Execução simultânea de um conjunto de tarefas, que podem ou não estar relacionadas. É uma forma de fazer muitas coisas ao mesmo tempo e está ligado a forma de se executar tarefas.

#### O que é programação paralela:

* Resumidamente, é quando você divide uma computação entre várias máquinas ou processadores que rodam ao mesmo tempo.

#### Em que casos é melhor utilizar programação paralela:

* Programação paralela é algo que você faz quando você quer aproveitar o fato de que você tem mais de um processador disponível para poder tentar achar mais rápido a resposta para o seu problema. Em situações que a performance não é importante não vale a pena fazer uma implementação paralela complexa e dependendo do algoritmo que você tem que implementar pode ser mais ou menos difícil criar uma versão paralela. Um exemplo bom do tipo de coisa que se dá bem com paralelismo é quando você tem computações "obviamente paralelizáveis". Por exemplo:

  * Para renderizar imagens 3d cada processador pode ser responsável por um pedaço diferente da tela.
  
  * Em alguns algoritmos numéricos como multiplicação de vetores e matrizes, cada processador pode ficar responsável por um trecho do vetor ou matriz separado e dá pra juntar as contas parciais no final.
  
  * Para compilar um programa com vários módulos, é posssivel usar paralelismo para compilar mais de um módulo ao mesmo tempo.

### Processo:

#### O que é um processo:

*  Um processo pode ser entendido como um programa que está em execução. Além disso, também pode ser definido como o ambiente onde o programa é executado. Este ambiente, além das informações importantes a execução do programa, possui também informações relativas aos recursos que o programa pode utilizar como espaço de endereçamento, uso do processador, área em disco, etc. 

#### Principais elementos do contexto de um processo:

* **Gerenciamento de processos:**
1. Registradores
2. Contador de programa
3. Palavra de estado do programa
4. Ponteiro de pilha
5. Estado do processo
6. Prioridade
7. Parâmetros de escalonamento
8. Identificador (ID) do processo
9. Processo pai
10. Grupos do processo
11. Sinais
12. Momento em que o processo iniciou
13. Tempo usado da CPU
14. Tempo de CPU do filho
15. Momento do próximo alarme

* **Gerenciamento de memória:**

1. Ponteiro para o segmento de código
2. Ponteiro para o segmento de dados
3. Ponteiro para o segmento de pilha

* **Gerenciamento de arquivos:**

1. Diretório-raiz
2. Diretório de trabalho
3. Descritores de arquivo
4. Identificador (ID) do usuário
5. Identificador do grupo

#### Estados de um processo:

* **Bloqueado:** Instruções estão bloqueadas aguardando ações de Entrada/Saída para continuar execução. (Quando um programa é bloqueado e recebe a entrada ou saída necessária, seu próximo estado vai ser o **Pronto**, e sua execução só ira continuar progredindo quando o escalonador o selecionar novamente).
* **Em Execução:** Instruções são executadas pelo escalonador.
* **Pronto:** Instruções estão prontas para serem executadas pelo escalonador.

### Thread:

#### O que é uma thread: 

* Uma thread é uma "Linha" de execução dentro de um processo. Cada thread tem o seu próprio estado de processador e a sua própria pilha, mas compartilha a memória atribuída ao processo com as outras threads “irmãs” (filhas do mesmo processo). As diversas threads que existem em um programa podem trocar dados e informações entre si e compartilhar os mesmos recursos do sistema. Assim, um usuário pode utilizar uma funcionalidade do sistema enquanto outras linhas de execução estão trabalhando e realizando outros cálculos e operações. As threads possuem vantagens e desvantagens ao dividir um programa em várias tarefas. Uma das vantagens é que isso facilita o desenvolvimento, visto que torna possível elaborar e criar o programa em módulos, experimentando-os isoladamente no lugar de escrever em um único bloco de código. Outro benefício das threads é que elas não deixam o processo parado, pois quando uma delas está aguardando um determinado dispositivo de entrada ou saída, ou ainda outro recurso do sistema, outra thread pode estar trabalhando. No entanto, uma das desvantagens é que com várias threads o trabalho fica mais complexo, justamente por causa da interação que ocorre entre elas.

### Escalonador:

#### O que é o escalonador: 

* O escalonador é responsável por decidir a ordem de execução dos processos prontos, ou seja, que escalona os processos. O escalonamento de processos é realizado por um algoritmo que visa tratar de forma eficiente e rápida os processos a serem tratados. Vários critérios podem ser definidos para a avaliação dos escalonadores, isso pode variar de acordo com o sistema operacional. No entanto, os critérios mais frequentes são:

  * **Tempo de execução (turnaround):** Mede o tempo decorrido entre a criação e o encerramento da tarefa, computando todos os tempos de processamento e de espera.
  * **Tempo de espera (waiting time):** Tempo total perdido pela tarefa na fila de prontos, aguardando o processador.
  * **Tempo de resposta:** Tempo decorrido entre a chegada de um evento ao sistema e o resultado imediato de seu processamento.   
  * **Eficiência:** Indica o grau de utilização do processador na execução das tarefas do usuário.
  * **Justiça:** Distribuição do processador entre as tarefas prontas.

### Contexto de execução de um programa:

* **Processo:** É o programa em execução e o ambiente onde o programa vai ser executado. Contém informações sobre a execução do programa e sobre os recursos que o programa pode utilizar como espaço de endereçamento, uso do processador, área em disco, etc.

* **Thread:** É uma "Linha" de execução dentro de um processo, no qual cada thread tem o seu próprio estado de processador e a sua própria pilha. Além disso, todas as threads dentro de um mesmo processo ocupam a mesma região de memória, o que facilita a troca de informações.

* **Escalonador:** É o responsável por decidir a ordem de execução dos processos levando em conta critérios como tempo de execução, tempo de espera, tempo de resposta, eficiência, justiça, etc.

### Incosistência de memória:

É natural que processos de uma aplicação concorrente compartilhem recursos. Mas o compartilhamento de recursos traz problemas que podem comprometer a execução da aplicação. Por este motivo, é necessário que os processos de uma aplicação concorrente sejam sincronizados pelo sistema operacional com o objetivo de garantir o processamento correto dos programas. Caso não haja uma gerência no uso concorrente dos recursos compartilhados, inconsistências nos dados podem ocorrer.

* **Como ocorre e como lidar:** Existem vários pontos que podem ser observados para entender como ocorre a incosistência de memória, mas o mais importante para entender agora é que um programa escrito de acordo com o paradigma de programação concorrente precisa obedecer algumas propriedades que vão servir como base para um execução segura de um programa, são elas:

  * **Safety property:** Garante que o programa nunca entra em um estado indesejado, ou seja, um estado em que as variáveis tem valores indesejados.

  * **Liveness property:** Garante que o programa em algum momento entrará no estado desejado.

* **Estado:** Consiste nos valores das variáveis do programa em um dado momento durante sua execução.

* **Ações atômicas:** Um processo executa uma sequência de instruções, as quais são implementadas por uma ou mais ações indivisíveis, denominadas ações atômicas.

* **Historias:** Uma história é uma sequência de estados pela qual passa um programa concorrente em uma execução qualquer.

##### Para o próximo assunto é interessante refazer as anotações sobre os tópicos de incosistência de memória, para tratá-los de maneira mais detalhada e clara.