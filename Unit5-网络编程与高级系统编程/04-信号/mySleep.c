/*************************************************************************
	> File Name: mysleep.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Sun 27 Mar 2022 05:54:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


void sig_alarm(int signo){
    return ;
}

unsigned int mysleep(unsigned int sec){

    struct sigaction newact, oldact;

    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGALRM, &newact, &oldact);


    alarm(sec);
    pause();
    
    unsigned int unslept;
    unslept = alarm(0);

    sigaction(SIGALRM, &oldact, NULL);
    return unslept;
}

int main(void){


    int n = 5;
    while(n){
        printf("hello mysleep ls\n");
        mysleep(1);
        n--;
    }

    return 0;
}
