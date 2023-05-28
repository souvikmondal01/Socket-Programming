//Write a program for TCP chat client-server in c

#include<stdio.h>
#include<netinet/in.h> // sockaddr_in
#include<string.h> // bzero
#include<arpa/inet.h> // inet_addr
#include<unistd.h> // read , write

#define PORT 5035
int main(){
       int sockfd;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(PORT);
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("Enter the message to send : ");
       fgets(buffer,4096,stdin);
       fputs(buffer,stdout);
       while(buffer!="quit")
       {
         if(buffer=="quit")
         break;
         write(sockfd,buffer,4096);
         read(sockfd,buffer,4096);
         printf("\nServer message: %s",buffer);
         printf("\nType your message: ");
         fgets(buffer,4096,stdin);
       }
       close(sockfd);
       return(0);
}
