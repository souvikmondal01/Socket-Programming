// Write a program for socket programming in c

#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#define PORT 8080

int main(){
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *fun_client = "Client";
	char buffer[2048] = {0};
	
	if((sock = socket(AF_INET, SOCK_STREAM, 0))<0){
		printf("\nSocket went wrong\n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
		printf("\nInvalid Address");
		return -1;
	}
	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
		printf("No Connection");
		return -1;
	}
	send(sock, fun_client, strlen(fun_client), 0);
	printf("Hello message sent\n");
	printf("%s\n", buffer);
	
	return 0;
}

