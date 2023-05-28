// Write a program for TCP socket(date & time) in c

#include<stdio.h>
#include<netinet/in.h> // sockaddr_in
#include<string.h> // bzero
#include<time.h> // time
#include <unistd.h> //wrire
#include <stdlib.h> //exit 
int main(){
	struct sockaddr_in sa ,cli;
	int sockfd,conntfd,len,ch;
	char str[100];
	time_t tick;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd<0){
		printf("error in socket\n");
		exit(0);
	}else 
		printf("Socket opened\n");
		
	bzero(&sa,sizeof(sa));
	sa.sin_port=htons(5600);
	sa.sin_addr.s_addr=htonl(0);

	if(bind(sockfd,(struct sockaddr*)&sa,sizeof(sa))<0){
		printf("Error in binding\n");
	}
	else
		printf("Binded Successfully\n");
	listen(sockfd,50);
	
	for(;;){
		len=sizeof(ch);
		conntfd=accept(sockfd,(struct sockaddr*)&cli,&len);
		printf("Accepted\n");
		tick=time(NULL);
		snprintf(str,sizeof(str),"%s",ctime(&tick));
		printf("%s",str);
		write(conntfd,str,100);
	}
}