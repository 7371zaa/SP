#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
  

int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(7778);
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    
    char buff[1024];
    int n = 0;
    bzero(buff, sizeof(buff));
    printf("Enter the string : ");
    scanf("%s", buff);
    write(sockfd, buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    printf("From Server : %s", buff);

    close(sockfd);
} 
