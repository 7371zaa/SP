#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
  
int main() 
{
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;
      
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
      
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
      
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8888);
      
    bind(
        sockfd,
        (const struct sockaddr *)&servaddr, 
        sizeof(servaddr)
    );
    int len, n;
  
    len = sizeof(cliaddr);

    while (1) 
    {
        n = recvfrom(
            sockfd, 
            (char *)buffer, 
            1024, 
            MSG_WAITALL, 
            (struct sockaddr*) &cliaddr,
            (socklen_t*)&len
        );
        buffer[n] = '\0';
        printf("Client : %s\n", buffer);
        sendto(
            sockfd, 
            (const char *)buffer, 
            strlen(buffer), 
            MSG_CONFIRM, 
            (const struct sockaddr *) &cliaddr,
            len
        );
    }
      
    return 0;
}
