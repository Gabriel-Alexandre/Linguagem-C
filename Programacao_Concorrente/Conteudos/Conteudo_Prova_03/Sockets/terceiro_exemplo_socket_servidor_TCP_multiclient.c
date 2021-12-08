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
#define QTD_CLIENTES 10
#define ADDR_SIZE 16

int client_counter = 0;

void *handle_client(void *p)
{

    int my_client_fd = (int)p;

    char *welcome_msg = "BEMVINDO\n";

    write(my_client_fd, welcome_msg, strlen(welcome_msg));

    while (1)
    {
        char buffer[TAM_MSG];
        char msg_to_client[TAM_MSG];
        int read_size;
        read_size = read(my_client_fd, buffer, TAM_MSG);
        if (read_size > 0)
        {
            printf("Client: %s\n", buffer);
            if (strncmp("exit", buffer, 4) == 0)
            {
                close(my_client_fd);
                client_counter--;
                pthread_exit(NULL);
            }
        }

        sprintf(msg_to_client, "Contador clientes: %d\n", client_counter);

        write(my_client_fd, msg_to_client, strlen(msg_to_client));
    }
}

int main(void)
{
    int server_fd;
    int client_fd[QTD_CLIENTES];
    int client_info_len[QTD_CLIENTES];
    int client_index = 0;

    unsigned int server_port = 0;
    struct sockaddr_in server_info;
    struct sockaddr_in client_info[QTD_CLIENTES];
    pthread_t client_thread[QTD_CLIENTES];

    printf("Digite a porta do servidor: ");
    scanf("%d", &server_port);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        printf("Problemas na criacao do socket!\n");
        exit(0);
    }
    else
    {
        bzero(&server_info, sizeof(server_info));

        for (int i = 0; i < QTD_CLIENTES; i++)
        {
            bzero(&client_info[i], sizeof(client_info[i]));
        }

        server_info.sin_family = AF_INET;
        server_info.sin_addr.s_addr = htonl(INADDR_ANY);
        server_info.sin_port = htons(server_port);

        if ((bind(server_fd, (const struct sockaddr *)&server_info, sizeof(server_info))) != 0)
        {
            printf("Problemas no bind()\n");
            exit(0);
        }
        else
        {
            printf("Aguardando conexoes na porta %d ", server_port);

            if (listen(server_fd, QTD_CLIENTES) != 0)
            {
                printf("\nErro ao invocar funcao listen()\n");
                exit(0);
            }
            else
            {
                printf("...\n");
                char addr_buf[ADDR_SIZE + 1];

                while (client_fd[client_index] = accept(server_fd,
                                                        (struct sockaddr *)&client_info[client_index].sin_addr,
                                                        &client_info_len[client_index]))
                {

                    char *client_ip_addr = inet_ntoa(client_info[client_index].sin_addr);
                    printf("[%d] Recebi conexao de %s\n", client_index, client_ip_addr);

                    pthread_create(&client_thread[client_index], NULL, handle_client,
                                   (void *)client_fd[client_index]);

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
