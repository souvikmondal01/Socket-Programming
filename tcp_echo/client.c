//Write a program for TCP echo client-server in c

#include<stdio.h> // basic c header
#include<unistd.h> // has the sockaddr_in structure
#include<netinet/in.h> // has functions for read and write operations
#include<arpa/inet.h> //inet_addr

#define PORT 5035

int main(){
	int sockfd;
	struct sockaddr_in serv_addr;
	char buffer[4096];
	sockfd = socket(AF_INET, SOCK_STREAM,0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(PORT);
	printf("\nReady for sending...");
	connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	printf("\nEnter the message to send\n");
	printf("\nClient: ");
	fgets(buffer,4096,stdin);
	write(sockfd,buffer,4096);
	printf("Server echo: %s",buffer);
	close(sockfd);

	return 0;
}