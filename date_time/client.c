// Write a program for TCP socket(date & time) in c

#include<stdio.h>
#include<netinet/in.h> // ockaddr_in
#include <stdlib.h> // exit
#include <strings.h> // bzero
#include <unistd.h> // read
int main(){
	struct sockaddr_in sa,cli;
	int n,sockfd,len;
	char buff[100];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd<0){ 
		printf("Error in Socket\n");
		exit(0);
	}
	else 
		printf("Socket is Opened\n");
		
	bzero(&sa,sizeof(sa));
	sa.sin_family=AF_INET;
	sa.sin_port=htons(5600);
	
	if(connect(sockfd,(struct sockaddr*)&sa,sizeof(sa))<0){
		printf("Error in connection failed\n");
		exit(0);
	}else
		printf("connected successfully\n");
	
	if(n=read(sockfd,buff,sizeof(buff))<0){
		printf("Error in Reading\n");
		exit(0);
	}
	else
		printf("Message Read: %s\n",buff);
	
}