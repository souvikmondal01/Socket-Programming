//Write a program for UDP echo client-server in c

#include<stdio.h>
#include<netinet/in.h> // sockaddr_in
#include<string.h> // bzero
#include<arpa/inet.h> // inet_addr

#define PORT 5035
#define MAXLINE 1024
int main(){
	int sockfd,n;
	socklen_t len;
	char sendline[1024],recvline[1024];
	struct sockaddr_in servaddr;
	strcpy(sendline,"");
	printf("Enter the message: ");
	scanf("%s",sendline);
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	len=sizeof(servaddr);
	sendto(sockfd,sendline,MAXLINE,0,(struct sockaddr*)&servaddr,len);
	n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
	recvline[n]=0;
	printf("\nServer's Echo : %s\n",recvline);
	
	return 0;
}