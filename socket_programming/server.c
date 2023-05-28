// Write a program for socket programming in c

#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#define PORT 8080

int main(){
	int sock_fd, new_socket, valread;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[2048];
	char *fun = "Souvik Mondal from Server";
	
	if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
		printf("Error, SCOKET went wrong\n");
		return -1;
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if(bind(sock_fd, (struct sockaddr *)&address,sizeof(address))<0){
		printf("Binding went wrong\n");
		return -1; 
	}
	if(listen(sock_fd, 4)<0){
		printf("Listining went wrong\n");
		return -1;
	}
	if((new_socket = accept(sock_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
		printf("Accept went wrong\n");
		return -1;
	}
	valread = read(new_socket, buffer, 2048);
	printf("%s\n", buffer);
	send(new_socket, fun, strlen(fun),0);
	printf("The message sent\n");
	
	return 0;
}

