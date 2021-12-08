#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>

#define TAM_STR_HOST 100
#define TAM_MSG 100

int main(void)
{
    int meu_socket_stream;
    int connection_result;
    int porta_servidor;
    char host_servidor[TAM_STR_HOST];
    struct sockaddr_in endereco_srv;
    struct sockaddr_in endereco_recv;
    char msg[TAM_MSG];
    char msg_recv[TAM_MSG];

    printf("Digite o endereco do servidor: ");
    gets(host_servidor);

    printf("Digite a porta usada na conexao: ");
    scanf("%d", &porta_servidor);

    // Configuração padrão [Inicio]

    meu_socket_stream = socket(PF_INET, SOCK_STREAM, 0); // TCP

    bzero(&endereco_srv, sizeof(endereco_srv));

    endereco_srv.sin_family = AF_INET;
    endereco_srv.sin_port = htons(porta_servidor);
    inet_aton(host_servidor, &endereco_srv.sin_addr);

    // Configuração padrão [FIM]

    // Verificação de conexão [INICIO]

    connection_result = connect(meu_socket_stream, &endereco_srv, sizeof(endereco_srv));

    if (connection_result == 0)
    {
        printf("Conectado ao servidor %s na porta %d\n", host_servidor, porta_servidor);
    }
    else
    {
        printf("Falha na conexao com servidor %s\n", host_servidor);
        exit(0);
    }

    // Verificação de conexão [FIM]

    // Troca de mensagens entre cliente e servidor [INICIO]

    while (1)
    {
        printf("Digite uma mensagem: ");
        scanf(" %s", msg);
        if (strcmp(msg, "exit") == 0)
        {
            close(meu_socket_stream);
            printf("Saindo...\n");
            exit(0);
        }
        sendto(meu_socket_stream, (void *)msg, strlen(msg), 0, &endereco_srv, sizeof(endereco_srv));
        recvfrom(meu_socket_stream, &msg_recv, TAM_MSG, 0, &endereco_recv, sizeof(endereco_recv));
        printf("Mensagem do servidor: %s\n", msg_recv);
    }

    // Troca de mensagens entre cliente e servidor [FIM]

    return 0;
}

// -> Informações de funcionamento das funçoes posso consultar no link abaixo:
// - https://www.youtube.com/watch?v=GaxjJvMnz-I&t=554s

/*
Comandos para teste do programa:

- nc -l -p (porta) [Usado para testar o cliente -> Cria um servidor que recebe mensagem]
- endereço: 127.0.0.1 (localhost)
- porta: posso escolher qual será usada

*/