#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>


int main(){
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);//дескриптор сокета

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(7778);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));//связывание сокета сервера с адресом, указатель на структуру с адресом +длина структуры
    listen(sockfd, 5);

    len = sizeof(cli);


    char buffer[1024];
    int n;
    while (1) {
        connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
        bzero(buffer, 1024);
        read(connfd, buffer, sizeof(buffer));
        printf("Client : %s\n", buffer);
        bzero(buffer, 1024);
        n = 0;

        while ((buffer[n++] = getchar()) != '\n');
        write(connfd, buffer, sizeof(buffer));
    }

    close(sockfd);
} 
