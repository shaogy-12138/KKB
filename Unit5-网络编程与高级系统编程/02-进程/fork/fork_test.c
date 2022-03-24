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
    int i = 0;
    for(i = 0; i < 10; i++){
        pid_t pid = fork();// 父进程拿到的是子进程的id  子进程拿到的是0；parent process get child parent pid; child process get 0

        if(pid < 0){
            perror("fork");
            exit(1);
        }

        if(!pid){
            printf("child[%d], self = %d, ppid = %d\n", i, getpid(), getppid());
            break;
        }else{
            
        }
        
    }

    return 0;
}
