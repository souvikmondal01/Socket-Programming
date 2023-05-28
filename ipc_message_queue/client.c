// Write a program for IPC message queue in c

#include <stdio.h>
#include<stdlib.h> // exit
#include <string.h> // strcpy
#include <sys/msg.h> //  msgsnd, msgrcv

int main()
{
    struct msgbht
    {
        long mtype;
        char mtext[100];
    } send, recv;
    int msg, len;
    msg = msgget((key_t)25, IPC_CREAT | 0666);
    if (msg < 0)
    {
        perror("Message faild");
        exit(1);
    }
    strcpy(send.mtext, "I am fine thank you");
    send.mtype = 2;
    len = strlen(send.mtext);
    if (msgrcv(msg, &recv, 100, 1, 0) == -1)
    {
        perror("Message faild");
        exit(1);
    }
    if (msgsnd(msg, &send, len, 0) == -1)
    {
        perror("Message faild");
        exit(1);
    }
    printf("Message from program 1 is : \n%s\n", recv.mtext);
}