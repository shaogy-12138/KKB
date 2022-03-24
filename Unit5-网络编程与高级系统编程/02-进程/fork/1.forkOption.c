/*************************************************************************
	> File Name: 1.forkOption.c
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Mon 14 Mar 2022 08:07:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<error.h>
#include<stdlib.h>
#include<time.h>


int main(void){

    char *msg = NULL;
    int count = 0;
    pid_t pid = fork();// 父进程拿到的是子进程的id  子进程拿到的是0；parent process get child parent pid; child process get 0

    if(pid < 0){
        perror("fork");
        exit(1);
    }

    if(pid == 0){
        msg = " this is child process~";
        count = 5;
        printf("%s, pid = %d, ppid = %d\n", msg, getpid(), getppid());
    }else{
        count = 3;
        msg = " this is parent process!\n";
        printf("%s, cpid = %d, pid = %d, ppid = %d\n", msg, pid, getpid(), getppid());
        
    }

    while(0){
        printf(msg);
        count--;
        sleep(1); //阻塞/挂起
    }
    return 0;
}
