//Write a program for UDP echo client-server in c

#include<stdio.h>
#include<netinet/in.h> // sockaddr_in
#include<string.h> // bzero

#define PORT 5035
#define MAXLINE 1024
int main(){
	int sockfd,n;
	socklen_t len;
	char msg[1024];
	struct sockaddr_in serv_addr,cli_addr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(PORT);
	printf("Binded");
	bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	printf("\nListening...\n\n");
	
	for(;;){
	
		len=sizeof(cli_addr);
		n=recvfrom(sockfd,msg,MAXLINE,0,(struct sockaddr*)&cli_addr,&len);
		printf("Client's Message: %s\n",msg);
		if(n<6)
			perror("send error");
	     	sendto(sockfd,msg,n,0,(struct sockaddr*)&cli_addr,len);
	}
	
	return 0;
}