/*************************************************************************
	> File Name: msgQueue.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Wed 23 Mar 2022 10:37:14 PM CST
 ************************************************************************/

#include<stdio.h>

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include<strings.h>
#include<sys/msg.h>


#define MSGLEN 20
typedef struct msgbuf{
    long mtype;
    char mtext[MSGLEN];
}MSG;


int main(void){




    key_t key = ftok("../1.sh", 99);

    printf("key = %0x\n", key);
    int mqid = msgget(key, IPC_CREAT | 0666);

    printf("mid = %d\n",mqid);

    

    // send message
    MSG msg;
    msg.mtype = 1;
    strncpy(msg.mtext, "hello world\n", MSGLEN);
    int snd1 = msgsnd(mqid, &msg, MSGLEN, IPC_NOWAIT);

    msg.mtype = 2;
    strncpy(msg.mtext, "xiaokai:online\n", MSGLEN);
    int snd2 = msgsnd(mqid, &msg, MSGLEN, IPC_NOWAIT);


    // recv message 
    
    //ssize_t rcv = msgrcv(mqid, str, )
    
    
    return 0;
}
