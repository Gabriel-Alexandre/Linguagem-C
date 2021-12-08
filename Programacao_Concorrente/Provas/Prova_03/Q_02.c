#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TAM_MSG 50
#define QTD_CLIENTES 5
#define ADDR_SIZE 16

int client_counter = 0;

// Thread que trata cada cliente
void *handle_client(void *p) {

    int my_client_fd = (int)p;

    char *welcome_msg = "WELCOME\n";

    write(my_client_fd, welcome_msg, strlen(welcome_msg));

    // Envio e recebimento de dados
    while (1) {
        // Variávies de armazenamento de mensagem
        char buffer[TAM_MSG];
        char msg_to_client[TAM_MSG];
        int read_size;

        // Aguarda o recebimento dos dados
        read_size = read(my_client_fd, buffer, TAM_MSG);
        if (read_size > 0) {
            printf("Client: %s\n", buffer);
            // Encerra conexão com o cliente
            if (strncmp("FINISH", buffer, 6) == 0) {
                close(my_client_fd);
                client_counter--;
                pthread_exit(NULL);
            }
            // Inverte mensagem recebida depois de BCKWRD
            else if(strncmp("BCKWRD", buffer, 6) == 0) {
                char msg[TAM_MSG];
                int i = 7;
                while(buffer[i] != '\n') {
                    i++;
                }

                strncpy(msg, buffer + 7, i);

                int index, j;

                for(index = 0, j = strlen(buffer) - 2; j >= 7; index++, j--) {
                    msg[index] = buffer[j];
                }         

                // Envia dados TCP mostrando mensagem invertida
                write(my_client_fd, msg, strlen(msg));
                for(int i = 0; i < TAM_MSG; i++) {
                    buffer[i] =  0;
                }
            }
            // Gera número aleatório entre 0 e 1000
            else if(strncmp("RNDNUM", buffer, 6) == 0) {
                char msg[8];
                int valor = rand() % 1001;

                sprintf(msg, "%d", valor);  

                int i = 0;

                while(msg[i] != '\0') {
                    i++;
                }
                msg[i] = '\n';
                msg[i+1] = '\0';

                // Envia dados TCP mostrando o valor gerado
                write(my_client_fd, msg, strlen(msg));
            }
            // Envia mensagem de erro caso não seja digitado uma opção válida
            else  {
                char *msg = "ERROR\n";

                // Envia dados TCP mostrando mensagem de erro
                write(my_client_fd, msg, strlen(msg));
            }
        }

        sprintf(msg_to_client, "Contador clientes: %d\n", client_counter);

        write(my_client_fd, msg_to_client, strlen(msg_to_client));
    }
}

int main(void) {
    int server_fd;
    int client_fd[QTD_CLIENTES];
    int client_info_len[QTD_CLIENTES];
    int client_index = 0;
    time_t t;

    srand((unsigned)time(&t));
    unsigned int server_port = 8600;
    struct sockaddr_in server_info;
    struct sockaddr_in client_info[QTD_CLIENTES];
    pthread_t client_thread[QTD_CLIENTES];

    // Cria socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Problemas na criacao do socket!\n");
        exit(0);
    }
    else {
        // Zera estrutura do servidor
        bzero(&server_info, sizeof(server_info));

        // Zera estruturas dos clientes
        for (int i = 0; i < QTD_CLIENTES; i++) {
            bzero(&client_info[i], sizeof(client_info[i]));
        }

        // Preenchendo elementos da estrutura do servidor
        server_info.sin_family = AF_INET;
        server_info.sin_addr.s_addr = htonl(INADDR_ANY);
        server_info.sin_port = htons(server_port);

        // Associando estrutura do servidor com o socket criado
        if ((bind(server_fd, (const struct sockaddr *)&server_info, sizeof(server_info))) != 0) {
            printf("Problemas no bind()\n");
            exit(0);
        }
        else {
            printf("Aguardando conexoes na porta %d ", server_port);

            // Habilitando o socket a aceitar pedidos de conexão
            if (listen(server_fd, QTD_CLIENTES) != 0) {
                printf("\nErro ao invocar funcao listen()\n");
                exit(0);
            }
            else {
                printf("...\n");
                char addr_buf[ADDR_SIZE + 1];

                // Recebendo pedidos de conexão por parte da aplicação cliente
                while (client_fd[client_index] = accept(server_fd,
                                                        (struct sockaddr *)&client_info[client_index].sin_addr,
                                                        &client_info_len[client_index]))
                {

                    char *client_ip_addr = inet_ntoa(client_info[client_index].sin_addr);
                    printf("[%d] Recebi conexao de %s\n", client_index, client_ip_addr);

                    // Criando threads para lidar com cada cliente específicamente
                    pthread_create(&client_thread[client_index], NULL, handle_client,
                                   (void *)client_fd[client_index]);

                    // Controle do número de conexões
                    client_counter++;
                    client_index++;
                    client_index = client_index % 10;

                    printf("Total de %d clientes conectados\n", client_counter);
                }
            }
        }
    }
    return 0;
}
