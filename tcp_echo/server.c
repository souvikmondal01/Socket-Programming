//Write a program for TCP echo client-server in c

#include<stdio.h> // basic c header
#include<netinet/in.h> // has the sockaddr_in structure
#include<unistd.h> // has functions for read and write operations

#define PORT 5035

int main(){
	
	int sockfd,newsockfd,clength;
	struct sockaddr_in serv_addr,cli_addr;
	char buffer[4096];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	printf("\nStart");
	bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	printf("\nListening...\n");	
	listen(sockfd,5);
	clength = sizeof(cli_addr);
	newsockfd = accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
	printf("\nAccepted\n");
	read(newsockfd,buffer,4096);
	printf("\nClient message: %s",buffer);
	write(newsockfd,buffer,4096);
	close(sockfd);
	
	return 0;
}
