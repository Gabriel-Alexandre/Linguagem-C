## Impressões:

#### Impressões do resultado:

* Conforme mostrado nos prints, na maior parte dos testes, o tempo de criação de processos foi aproximadamente o dobro do tempo de criação das threads, isso pode ser justificado a partir da demanda de recursos necessários para criação de cada um, pois enquanto as threads necessitam apenas das informações do contador de programa, pilha, registrador e estado, os processos nessecitam de muitos recursos a mais como PID, pelo menos uma thread, uso do processador, area de disco, entre outras depedências que o tornam mais custoso.

#### Diferença entre threads e processos:

* **Processo:** É o programa em execução e o ambiente onde o programa vai ser executado. Contém informações sobre a execução do programa e sobre os recursos que o programa pode utilizar como espaço de endereçamento, uso do processador, área em disco, etc.

* **Thread:** É uma "Linha" de execução dentro de um processo, no qual cada thread tem o seu próprio estado de processador e a sua própria pilha. Além disso, todas as threads dentro de um mesmo processo ocupam a mesma região de memória, o que facilita a troca de informações.
