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

int main(void){



    sigset_t set, oldset;
    // 1. 集合清空
    sigemptyset(&set);

    // 2. 添加信号到集合中
    sigaddset(&set, 2);
    sigaddset(&set, 11);

    // 3. 给set中信号加屏蔽字， 将set中所有信号的屏蔽状态返回给oldset; 这个函数本身就是设置信号屏蔽字的
    sigprocmask(SIG_BLOCK, &set, &oldset);


    int n = 10;
    while(n--){
        sleep(1);
        printf("sleep one second\n");
    }
    // 4. 信号集中的屏蔽状态恢复为阻塞前的状态
    sigprocmask(SIG_SETMASK, &oldset, NULL);


    // 当./a.out运行时，由于3设置了阻塞，因此，在4恢复之前的10s内使用ctrl + c结束状态时无效的，但是这个结束信号已经放到消息队列，等到4恢复之后，立即执行
    // 因此 此部分往下是不会执行的
    n = 10;
    while(n--){
        sleep(1);
        printf("sleep one second 2\n");
    }
    return 0;
}
