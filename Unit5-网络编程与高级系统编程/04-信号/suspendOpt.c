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
    printf("this is alarm func\n");
    return ;
}

unsigned int mysleep(unsigned int sec){

    struct sigaction newact, oldact;
    sigset_t newmask, oldmask, susmask;
    // 设置信号集: 1. 清空  2. 添加
    sigempty(&newmask);
    sigaddset(&newmask, SIGALRM);

    // 阻塞信号

    sigprocmask(SIGBLOCK, &newmak, &oldmask);
    

    // 换动作
    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    sigaction(SIGALRM, &newact, &oldact);



    // 开启闹钟
    alarm(sec);

    // 如果使用pause，就会一直阻塞在这里，因为block永远不会有信号递达

    // 1.  读取原来的信号屏蔽字情况  2. 获取未block的mask
    susmask = oldmask;
    sigdeltsey(&susmask, SIGALRM);
    // 临时设置信号屏蔽字为susmask,并挂起等待信号到来
    sigsuspend(&susmask);
    
    unsigned int unslept;
    unslept = alarm(0);  //关掉闹钟并返回剩余见时间

    sigaction(SIGALRM, &oldact, NULL);
    sigprocmask(SIG_SETMASK,  &oldmask, NULL);
    return unslept;
}

int main(void){


    int n = 5;
    while(n){
        printf("hello mysleep ls\n");
        mysleep(2);
        n--;
    }

    return 0;
}
