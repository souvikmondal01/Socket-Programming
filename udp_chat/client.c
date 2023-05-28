//Write a program for UDP chat client-server in c

#include<stdio.h>
#include<netinet/in.h>// sockaddr_in
#include<string.h> // bzero
#include<arpa/inet.h> // inet_addr
#include<stdlib.h> // exit
#include<unistd.h> // close

#define MAX 80
#define PORT 43454
int main(){
	char buff[MAX];
	int sockfd,len,n;
	struct sockaddr_in servaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	if(sockfd==-1){
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	
	bzero(&servaddr,sizeof(len));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);
	len=sizeof(servaddr);
	
	for(;;){
		printf("\nEnter string: ");
		n=0;
		while((buff[n++]=getchar())!='\n');
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,len);
		bzero(buff,sizeof(buff));
		recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&len);
		printf("From Server: %s\n",buff);
		
		if(strncmp("exit",buff,4)==0){
			printf("Client Exit...\n");
			break;
		}
	}
	close(sockfd);
}
