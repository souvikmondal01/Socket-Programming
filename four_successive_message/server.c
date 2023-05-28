// Write a program to send four successive messages from the sender in c

#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int main(){
	struct msgbht{
		long mtype;
		char mtext[100];
	}send,recv;
	int msg,len;
	msg=msgget((key_t)25,IPC_CREAT|0666);
	if(msg<0){
		perror("Message failed\n");
		exit(1);
	}
	strcpy(send.mtext,"Hello, How are you?\n");
	send.mtype=1;
	len=strlen(send.mtext);
	if(msgsnd(msg,&send,len,0)==-1){
		perror("Message failed\n");
		exit(1);
	}
	strcpy(send.mtext,"Msg2:Where are you?\n");
	send.mtype=2;
	len=strlen(send.mtext);
	if(msgsnd(msg,&send,len,0)==-1){
		perror("Message failed");
		exit(1);
	}
	strcpy(send.mtext,"Msg3:What are you doing?\n");
	send.mtype=3;
	len=strlen(send.mtext);
	if(msgsnd(msg,&send,len,0)==-1){
		perror("Message failed\n");
		exit(1);
	}
	strcpy(send.mtext,"Msg4:Why are you here now?\n");
	send.mtype=4;
	len=strlen(send.mtext);
	if(msgsnd(msg,&send,len,0)==-1){
		perror("Message failed\n");
		exit(1);
	}
}
