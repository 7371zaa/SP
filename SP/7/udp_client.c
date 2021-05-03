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
    struct sockaddr_in servaddr;
  
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
    memset(&servaddr, 0, sizeof(servaddr));
      
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    servaddr.sin_addr.s_addr = INADDR_ANY;
      
    int n, len;
    
    printf("Input word:");
    scanf("%s", buffer);

    sendto(
        sockfd,
        (const char *)buffer,
        strlen(buffer),
        MSG_CONFIRM,
        (const struct sockaddr *)&servaddr, 
        sizeof(servaddr)
    );
    n = recvfrom(
        sockfd,
        (char *)buffer,
        1024, 
        MSG_WAITALL,
        (struct sockaddr *) &servaddr,
        (socklen_t*)&len
    );
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);
  
    close(sockfd);
}
