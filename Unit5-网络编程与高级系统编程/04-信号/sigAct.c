/*************************************************************************
	> File Name: sigMask.c
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



void undead(int signo){
    printf("get signo = %d, I'm happy, I'm alive\n", signo);
    return ;
}
int main(){


    // ba ctrl + c的动作修改


    struct sigaction newcat, oldact;
    newcat.sa_handler = undead;  // 绑定函数
    newcat.sa_flags = 0; //一般置0
    sigemptyset(&newcat.sa_mask);
    sigaction(SIGINT, &newcat, &oldact); //SIGINT 信号的行为定位newact， 将旧的动作保存到oldact
    int n = 20;
    while(n--){
        sleep(1);
    }


    sigaction(SIGINT, &oldact, NULL);// 将SIGINT 信号恢复为oldact， 不需要将当前的行为保存，所以定义为null
    return 0;
}
